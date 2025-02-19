/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/19 12:14:01 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_cast_ray(t_ray *ray, t_data *data)
{
	ray->pos = (2 * ray->pixel / WIDTH) - 1.0;
	ray->dir_x = data->player->dir_x + data->plane->x * ray->pos;
	ray->dir_y = data->player->dir_y + data->plane->y * ray->pos;
	/* ray->dir_x = 1.0 / sqrt(1 + (ft_get_tan(ray->angle) * ft_get_tan(ray->angle)));
	ray->dir_y = ray->dir_x * ft_get_tan(ray->angle);
	ray->dir_x = cos(ft_dtor(ray->angle));
	ray->dir_y = sin(ft_dtor(ray->angle)); */
	printf("RAY angle: %f, dir_x: %f, dir_y: %f\n", ray->angle, ray->dir_x, ray->dir_y);
	ray->dis = 0;
	ray->hori_int = NULL;
	ray->vert_int = NULL;
	printf("\nHORIZONTAL\n");
	ft_hori_intersection(ray, data);
	printf("\nVERTICAL\n");
	ft_vert_intersection(ray, data);
	printf("\n");
	if (ft_distance(ray->hori_int, data) < ft_distance(ray->vert_int, data))
	{
		printf("Printing wall for horizontal intersection\n");
		ft_print_wall(ray->hori_int, ray, data);
	}
	else
	{
		printf("Printing wall for vertical intersection\n");
		ft_print_wall(ray->vert_int, ray, data);
	}
}

void	ft_init_rays(t_data *data)
{
	int		i;
	double	start_angle;
	t_ray	**rays;
	t_ray	*ray;

	i = 0;
	start_angle = data->player->view_angle - (FOV / 2);
	rays = (t_ray **)malloc(WIDTH * sizeof(t_ray *));
	if (!rays)
		ft_game_cleanup(data, "malloc");
	data->rays = rays;
	while (i < WIDTH)
	{
		ray = (t_ray *)malloc(1 * sizeof(t_ray));
		if (!ray)
			ft_game_cleanup(data, "malloc");
		ray->pixel = i + 1;
		ray->angle = start_angle + (data->ray_angle * i);
		//ray->angle = start_angle + ((double)i / WIDTH) * FOV;
		rays[i] = ray;
		printf("%i-", i);
		ft_cast_ray(rays[i], data);
		i++;
	}	
	printf("FINISHED\n");
	ft_free_rays(rays);
	data->rays = NULL;
}
