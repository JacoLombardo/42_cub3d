/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 16:13:13 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_player(t_player *player, double angle_increment)
{
	double	old_dir_x;
	double	old_dir_y;
	double	cos_incr_angle;
	double	sin_incr_angle;

	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	cos_incr_angle = cos(angle_increment);
	sin_incr_angle = sin(angle_increment);
	player->dir_x = old_dir_x * cos_incr_angle - old_dir_y * sin_incr_angle;
	player->dir_y = old_dir_x * sin_incr_angle + old_dir_y * cos_incr_angle;
}

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
	if (keycode == XK_w || keycode == XK_Up)
	{
		data->player->mv_forward = 1;
		data->player->pos_x += data->player->dir_x * 3;
		data->player->pos_y += data->player->dir_y * 3;
	}
	if (keycode == XK_d || keycode == XK_Right)
		ft_rotate_player(data->player, ft_dtor(3.0));
	if (keycode == XK_a || keycode == XK_Left)
		ft_rotate_player(data->player, ft_dtor(-3.0));
	if (keycode == XK_s || keycode == XK_Down)
	{
		data->player->pos_x -= data->player->dir_x * 3;
		data->player->pos_y -= data->player->dir_y * 3;
	}
	ft_render_screen(data);
	return (0);
}
