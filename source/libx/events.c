/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 14:58:37 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_event_close_win(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	ft_render_screen(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_init_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
}

int	ft_events_keyboard(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == XK_Escape)
		ft_event_close_win(data);
	if (keycode == 119 || keycode == 65307)
	{
		printf("player position adjusted from x: %f, y: %f ", data->player->pos_x, data->player->pos_y);
		data->player->pos_x += data->player->dir_x;
		data->player->pos_y += data->player->dir_y;
		printf("player position adjusted\n");
		mlx_clear_window(data->mlx, data->win);
		ft_init_rays(data);
		mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
		// print_image_info(data->image);
	}
	if (keycode == 97 || keycode == 65361)
	{
		ft_set_player_dir(ft_move_orientation('l', data->player), data->player);
	}
	if (keycode == 100 || keycode == 65363)
	{
		ft_set_player_dir(ft_move_orientation('r', data->player), data->player);
	}
	if (keycode == XK_W)
		data->player->mv_forward = 1;
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
