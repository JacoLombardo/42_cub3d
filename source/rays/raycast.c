/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/15 16:43:34 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_cast_ray(t_ray *ray, t_data *data, int pixel)
{
	ray->pos = ((2 * pixel) / WIDTH) - 1;
	ray->dir_x = data->player->dir_x + data->plane->x * ray->pos;
	ray->dir_y = data->player->dir_y + data->plane->y * ray->pos;
	printf("RAY_DIR dir_x: %f, dir_y: %f\n", ray->dir_x, ray->dir_y);
	ray->dis = 0;
	ray->hori_int = NULL;
	ray->vert_int = NULL;
	printf("HORIZONTAL\n");
	ft_hori_intersection(ray, data);
	printf("VERTICAL\n");
	ft_vert_intersection(ray, data);
	if (ft_closer(ray->hori_int, ray->vert_int, data))
		printf("wall hori\n");
		//ft_print_wall(ray->hori_int);
	else
		printf("wall vert\n");
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
		ft_cast_ray(rays[i], data, i);
		i++;
	}
	printf("FINISHED\n");
	ft_free_rays(rays);
}
