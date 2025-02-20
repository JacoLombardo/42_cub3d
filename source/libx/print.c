/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 14:31:24 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_wall_height(double ray_distance)
{
	if (ray_distance <= 0.1)
		ray_distance = 0.1;
	return ((int) (HEIGHT / ray_distance));
}

void	ft_print_wall(t_ray *ray, t_data *data)
{
	int		pix_y;
	int		wall_height;

	//wall_height = get_wall_height(ray->perp_wall_dist);
	wall_height = (int)(WALL_HEIGHT / (ray->perp_wall_dist) * WIDTH);
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		calc_pixel(closest, data, pix_y, ray->pixel, wall_height);
		pix_y++;
	}
}

void	ft_print_wall2(int side, int pixel, double dis_perp, t_data *data)
{
	int		pix_y;
	int		wall_height;

	//wall_height = get_wall_height(dis_perp / GRID);
	wall_height = (int)(WALL_HEIGHT / (dis_perp / GRID) * WIDTH);
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		calc_pixel(side, data, pix_y, pixel, wall_height);
		pix_y++;
	}
}

int darken_color(int color, double factor)
{
	int	r;
	int	g;
	int	b;
	
	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	
	return (r << 16) | (g << 8) | b;
}

