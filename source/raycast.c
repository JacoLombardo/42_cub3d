/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/24 22:28:06 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calc_perp_wall(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->x - data->player->pos_x / GRID + (1
					- ray->step_x) / 2) / ray->dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->y - data->player->pos_y / GRID + (1
					- ray->step_y) / 2) / ray->dir_y;
	}
}

void	ft_calc_wall_hit(t_ray *ray, t_data *data)
{
	ray->hit_x = data->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->hit_y = data->player->pos_y + ray->perp_wall_dist * ray->dir_y;
}

void	ft_cast_ray(t_ray *ray, t_data *data)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->y += ray->step_y;
			ray->side = 1;
		}
		if (data->config->map[ray->y][ray->x] == '1')
			hit = 1;
	}
	ft_calc_perp_wall(ray, data);
	ft_calc_wall_hit(ray, data); // for texturing, i need to know where the ray hit the wall (coordinates)
	ft_calc_texture(ray, data);
	//printf("wall hit at x: %i, y: %i and perpwall: %f\n", ray->x, ray->y, ray->perp_wall_dist);
	ft_print_wall(ray, data);
}

void	ft_set_ray_utils(t_ray *ray, t_data *data)
{
	if (ray->dir_x < 0)
	{
		ray->side_dist_x = (data->player->pos_x - ray->x * GRID)
			* ray->delta_dist_x / GRID;
		ray->step_x = -1;
	}
	else
	{
		ray->side_dist_x = ((ray->x + 1) * GRID - data->player->pos_x)
			* ray->delta_dist_x / GRID;
		ray->step_x = 1;
	}
	if (ray->dir_y < 0)
	{
		ray->side_dist_y = (data->player->pos_y - ray->y * GRID)
			* ray->delta_dist_y / GRID;
		ray->step_y = -1;
	}
	else
	{
		ray->side_dist_y = ((ray->y + 1) * GRID - data->player->pos_y)
			* ray->delta_dist_y / GRID;
		ray->step_y = 1;
	}
}

void	ft_set_ray(int pixel, t_ray *ray, t_data *data)
{
	ray->x = (int)(data->player->pos_x / GRID);
	ray->y = (int)(data->player->pos_y / GRID);
	ray->pixel = pixel + 1;
	ray->angle = atan2(data->player->dir_y, data->player->dir_x) + (pixel
			/ (double)WIDTH - 0.5f) * FOV;
	ray->dir_x = cos(ray->angle);
	ray->dir_y = sin(ray->angle);
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ft_set_ray_utils(ray, data);
}

void	ft_init_rays(t_data *data)
{
	int		i;
	t_ray	**rays;
	t_ray	*ray;

	i = 0;
	rays = (t_ray **)malloc(WIDTH * sizeof(t_ray *));
	if (!rays)
		ft_game_cleanup(data, "malloc");
	data->rays = rays;
	while (i < WIDTH)
	{
		ray = (t_ray *)malloc(1 * sizeof(t_ray));
		if (!ray)
			ft_game_cleanup(data, "malloc");
		//printf("%i-", i);
		ft_set_ray(i, ray, data);
		rays[i] = ray;
		ft_cast_ray(rays[i], data);
		i++;
	}
	// ft_free_rays(rays);
	data->rays = NULL;
}
