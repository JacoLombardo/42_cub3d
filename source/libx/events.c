/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 13:30:15 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_event_close_win(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	ft_events_keyboard(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == XK_Escape)
		ft_event_close_win(data);
	if (keycode == 119)
	{
		data->player->pos_x += 30;
		data->player->pos_y += 30;
		printf("player position adjusted\n");
		mlx_clear_window(data->mlx, data->win);
		ft_init_rays(data);
		mlx_put_image_to_window(data->mlx, data->win, data->image->img, WIDTH, HEIGHT);
		print_image_info(data->image);
	}
	if (keycode == XK_S)
		data->player->mv_back = 1;
	return (0);
}


// void	update_game(t_data *data, t_player *player)
// {
// 	if (player->mv_forward)
// 	{
// 		player->pos_x += player->dir_x;
// 		player->pos_y += player->dir_y;
// 	}
// 	if (player->mv_back)
// 	{
// 		player->pos_x -= player->dir_x;
// 		player->pos_y -= player->dir_y;
// 	}
// }
