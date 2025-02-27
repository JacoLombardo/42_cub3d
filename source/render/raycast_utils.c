/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:36:08 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/27 21:18:55 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_calc_perp_wall(t_ray *ray, t_data *data)
{
	(void)data;
	if (ray->side == 0)
		//ray->perp_wall_dist = fabs(ray->x - data->player->pos_x / GRID);
		ray->perp_wall_dist = (ray->x - data->player->pos_x / GRID + (1 - ray->step_x) / 2) / ray->norm_dir_x;
	else
		//ray->perp_wall_dist = fabs(ray->y - data->player->pos_y / GRID);
		ray->perp_wall_dist = (ray->y - data->player->pos_y / GRID + (1 - ray->step_y) / 2) / ray->norm_dir_y;
}
