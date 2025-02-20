/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 14:43:54 by jalombar         ###   ########.fr       */
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
	if (keycode == XK_W)
		player->mv_forward = 1;
	if (keycode == XK_S)
		player->mv_back = 1;
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
