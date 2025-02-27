/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:02:36 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/27 21:09:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_move(double move_x, double move_y, t_data *data)
{
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	char	**map;

	map = data->config->map;
	pos_x = data->player->pos_x + move_x;
	pos_y = data->player->pos_y + move_y;
	// Adding a little collision margin
	if (move_x > 0)
		pos_x += GRID / 6;
	else if (move_x < 0)
		pos_x -= GRID / 6;
	if (move_y > 0)
		pos_y += GRID / 6;
	else if (move_y < 0)
		pos_y -= GRID / 6;
	x = pos_x / GRID;
	y = pos_y / GRID;
	if (!ft_inside_map(x, y, map) && map[y][x] == '0')
		return (1);
	else
		return (0);
}

int	ft_move_player_ws(char direction, t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (direction == 'w')
	{
		move_x = data->player->dir_x * STEP;
		move_y = data->player->dir_y * STEP;
	}
	else if (direction == 's')
	{
		move_x = -data->player->dir_x * STEP;
		move_y = -data->player->dir_y * STEP;
	}
	if (ft_check_move(move_x, move_y, data))
	{
		data->player->pos_x += move_x;
		data->player->pos_y += move_y;
	}
	return (1);
}

int	ft_move_player_ad(char direction, t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (direction == 'a')
	{
		move_x = data->player->dir_y * STEP;
		move_y = -data->player->dir_x * STEP;
	}
	else if (direction == 'd')
	{
		move_x = -data->player->dir_y * STEP;
		move_y = data->player->dir_x * STEP;
	}
	if (ft_check_move(move_x, move_y, data))
	{
		data->player->pos_x += move_x;
		data->player->pos_y += move_y;
	}
	return (1);
}

int	ft_rotate_player(t_player *player, double angle_increment)
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
	return (1);
}
