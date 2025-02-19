/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/02/19 11:57:10 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int get_wall_height(double ray_distance)
{
	if (ray_distance <= 0.1)
		ray_distance = 0.1;
	return ((int) (HEIGHT / ray_distance));
}

void	ft_print_wall(t_ray *ray, t_intersect *wall_int, t_data *data)
{
	int	pix_y;
	int	wall_height;
	double dis;
	
	dis = sqrt((wall_int->dis_x * wall_int->dis_x) + (wall_int->dis_y * wall_int->dis_y));
	wall_height = get_wall_height(dis);
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		calc_pixel(data, pix_y, ray->pixel, wall_height);
		pix_y++;
	}
}

