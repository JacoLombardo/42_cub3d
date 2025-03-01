/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/03/01 11:57:37 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_event_close_win(data);
	if (keycode == 119)
		data->keys[0] = 1;
	else if (keycode == 115)
		data->keys[1] = 1;
	else if (keycode == 97)
		data->keys[2] = 1;
	else if (keycode == 100)
		data->keys[3] = 1;
	else if (keycode == 65361)
		data->keys[4] = 1;
	else if (keycode == 65363)
		data->keys[5] = 1;
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->keys[0] = 0;
	else if (keycode == 115)
		data->keys[1] = 0;
	else if (keycode == 97)
		data->keys[2] = 0;
	else if (keycode == 100)
		data->keys[3] = 0;
	else if (keycode == 65361)
		data->keys[4] = 0;
	else if (keycode == 65363)
		data->keys[5] = 0;
	return (0);
}

int	ft_event_close_win(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	ft_events_keyboard(t_data *data)
{
	int	result;

	result = 0;
	if (data->keys[0])
		result += ft_move_player_ws('w', data);
	if (data->keys[1])
		result += ft_move_player_ws('s', data);
	if (data->keys[2])
		result += ft_move_player_ad('a', data);
	if (data->keys[3])
		result += ft_move_player_ad('d', data);
	if (data->keys[4])
		result += ft_rotate_player(data->player, ft_dtor(-1.0));
	if (data->keys[5])
		result += ft_rotate_player(data->player, ft_dtor(1.0));
	return (result);
}
