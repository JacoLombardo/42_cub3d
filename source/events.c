/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/02/08 16:16:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_events(t_data *data)
{
	mlx_hook(data->win_ptr, DestroyNotify, 0, event_close_win, data);
	mlx_key_hook(data->win_ptr, events_keyboard, data);
	// mlx_mouse_hook(data->win_ptr, events_mouse_press, data);
}
int	event_close_win(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int events_keyboard(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		event_close_win(data);
	return (0);
}
