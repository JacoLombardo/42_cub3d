/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:36:08 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/27 15:10:23 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_calc_perp_wall(t_ray *ray, t_data *data)
{
	(void)data;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	/* if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->x - data->player->pos_x / GRID + (1
					- ray->step_x) / 2) / ray->dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->y - data->player->pos_y / GRID + (1
					- ray->step_y) / 2) / ray->dir_y;
	} */
}

/* void	ft_calc_perp_wall(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = ((ray->x + 0.5 - data->player->pos_x / GRID) + (1
					- ray->step_x) / 2) / ray->dir_x;
	}
	else
	{
		ray->perp_wall_dist = ((ray->y + 0.5 - data->player->pos_y / GRID) + (1
					- ray->step_y) / 2) / ray->dir_y;
	}
} */

void	ft_calc_wall_hit(t_ray *ray, t_data *data)
{
	ray->hit_x = data->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->hit_y = data->player->pos_y + ray->perp_wall_dist * ray->dir_y;
}
