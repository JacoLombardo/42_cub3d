/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 15:37:29 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_wall_height(double ray_distance)
{
	if (ray_distance <= 0.1)
		ray_distance = 0.1;
	return ((int)(HEIGHT / ray_distance));
}

void	ft_print_wall(t_ray *ray, t_data *data)
{
	int		pix_y;
	int		wall_height;

	//wall_height = get_wall_height(ray->perp_wall_dist) * SCALING_FACTOR;
	wall_height = (int)(WALL_HEIGHT / (ray->perp_wall_dist) * WIDTH) * SCALING_FACTOR;
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		calc_pixel(ray->side, data, pix_y, ray->pixel, wall_height);
		pix_y++;
	}
}

int	darken_color(int color, double factor)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	return ((r << 16) | (g << 8) | b);
}

