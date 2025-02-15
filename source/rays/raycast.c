/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/15 12:33:55 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_cast_ray(t_ray *ray, t_data *data)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->dis = 0;
	ray->hori_int = NULL;
	ray->vert_int = NULL;
	ft_hori_intersection(ray, data);
	ft_vert_intersection(ray, data);
	if (ft_farer(ray->hori_int, ray->vert_int))
		printf("wall vert\n");
		//ft_print_wall(ray->hori_int);
	else
		printf("wall hori\n");
		//ft_print_wall(ray->vert_int);
}

void	ft_init_rays(t_data *data)
{
	int		i;
	double	start_angle;
	t_ray	**rays;
	t_ray	*temp;

	i = 0;
	start_angle = 90 - (FOV / 2);
	rays = (t_ray **)malloc(WIDTH * sizeof(t_ray *));
	while (i < WIDTH)
	{
		temp = (t_ray *)malloc(1 * sizeof(t_ray));
		temp->angle = start_angle + (data->ray_angle * i);
		rays[i] = temp;
		// double cameraX = 2 * x / double(w) - 1;
		// double rayDirX = dirX + planeX * cameraX;
		// double rayDirY = dirY + planeY * cameraX;
		ft_cast_ray(rays[i], data);
		i++;
	}
	ft_free_rays(rays);
}
