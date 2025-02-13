/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/02/09 14:46:23 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_event_close_win(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int events_keyboard(int keycode, t_data *data, t_player *player)
{
	if (keycode == XK_Escape)
		event_close_win(data);
	if (keycode == XK_W)
	{
		player->pos_x += player->dir_x;
		player->pos_y += player->dir_y;
	}
	if (keycode == XK_S)
	{
		player->pos_x -= player->dir_x;
		player->pos_y -= player->dir_y;
	}
	return (0);
}
