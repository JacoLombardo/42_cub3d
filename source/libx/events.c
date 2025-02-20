/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:45 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 16:32:32 by jalombar         ###   ########.fr       */
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

int	ft_inside_map(int x, int y, char **map)
{
	if (x < 0 || y < 0)
		return (1);
	else if (y > ft_tab_len(map) - 1)
		return (1);
	else if (x > (int)ft_strlen(map[y]) - 1)
		return (1);
	else
		return (0);
}

void	ft_move_player(char direction, t_data *data, char **map)
{
	int	pos_x;
	int	pos_y;

	if (direction == 'u')
	{
		pos_x = (data->player->pos_x + (data->player->dir_x * STEP)) / GRID;
		pos_y = (data->player->pos_y + (data->player->dir_y * STEP)) / GRID;
		printf("x: %i, y: %i, and map value: %c\n", pos_x, pos_y, map[pos_y][pos_x]);
		if (!ft_inside_map(pos_x, pos_y, map) && map[pos_y][pos_x] == '0')
		{
			data->player->pos_x += data->player->dir_x * STEP;
			data->player->pos_y += data->player->dir_y * STEP;
			ft_render_screen(data);
		}
	}
	else if (direction == 'd')
	{
		pos_x = (data->player->pos_x - data->player->dir_x * STEP) / GRID;
		pos_y = (data->player->pos_y - data->player->dir_y * STEP) / GRID;
		if (!ft_inside_map(pos_x, pos_y, map) && map[pos_y][pos_x] == '0')
		{
			data->player->pos_x -= data->player->dir_x * STEP;
			data->player->pos_y -= data->player->dir_y * STEP;
			ft_render_screen(data);
		}
	}
}

int	ft_events_keyboard(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == XK_Escape)
		ft_event_close_win(data);
	if (keycode == XK_Up || keycode == XK_w)
		ft_move_player('u', data, data->config->map);
	if (keycode == XK_Down || keycode == XK_s)
		ft_move_player('d', data, data->config->map);
	if (keycode == XK_d || keycode == XK_Right)
		ft_rotate_player(data->player, ft_dtor(3.0));
	if (keycode == XK_a || keycode == XK_Left)
		ft_rotate_player(data->player, ft_dtor(-3.0));
	}
	ft_render_screen(data);
	return (0);
}
