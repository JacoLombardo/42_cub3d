/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:11:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/15 12:30:34 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_wall(t_2D *intersection, t_data *data)
{
	printf("POS  x: %i, y: %i\n", intersection->x, intersection->y);
	if (data->config->map[intersection->y][intersection->x] == '1')
	{
		printf("WALL FOUND!\n");
		return (1);
	}
	else
	{
		printf("wall not found\n");
		return (0);
	}
}

t_2D	*ft_hori_coordinates(t_ray *ray, t_data *data, int first)
{
	int	dir_y;

	if (ray->dir_y < 0)
		dir_y = -1;
	else
		dir_y = 64;
	if (first)
	{
		ray->vert_int->y = (floor(data->player->pos_y) * GRID) + (dir_y);
		ray->vert_int->x = data->player->pos_x + ((data->player->pos_y 
					- (ray->vert_int->y / GRID)) / tan(ray->angle));
	}
	else
	{
		ray->vert_int->y = ray->vert_int->y + (ray->ya / GRID);
		ray->vert_int->x = ray->vert_int->x + (ray->xa / GRID);
	}
	return (ray->vert_int);
}

t_2D	*ft_vert_coordinates(t_ray *ray, t_data *data, int first)
{
	int	dir_x;

	if (ray->dir_x < 0)
		dir_x = -1;
	else
		dir_x = 64;
	if (first)
	{
		ray->hori_int->x = (floor(data->player->pos_x) * GRID) + (dir_x);
		ray->hori_int->y = data->player->pos_y + ((data->player->pos_x 
					- (ray->hori_int->x / GRID)) / tan(ray->angle));
	}
	else
	{
		ray->hori_int->y = ray->hori_int->y + (ray->hori_int->ya / GRID);
		ray->hori_int->x = ray->hori_int->x + (ray->hori_int->xa / GRID);
	}
	return (ray->hori_int);
}

void	ft_hori_intersection(t_ray *ray, t_data *data)
{
	t_2D	*point;

	point = (t_2D *)malloc(1 * sizeof(t_2D));
	if (!point)
		return ;
	point->xa = ft_calc_xa(ray);
	point->ya = GRID / 2;
	point->dis_x = point->xa;
	point->dis_y = point->ya;
	point->x = 0;
	point->y = 0;
	ray->hori_int = point;
	ray->hori_int = ft_hori_coordinates(ray, data, 1);
	while (1)
	{
		if (ft_check_wall(ray->hori_int, data))
			return ;
		ray->hori_int = ft_hori_coordinates(ray, data, 0);
		point->dis_x += point->xa;
		point->dis_y += point->ya;
	}
}

void	ft_vert_intersection(t_ray *ray, t_data *data)
{
	t_2D	*point;

	point = (t_2D *)malloc(1 * sizeof(t_2D));
	if (!point)
		return ;
	point->xa = GRID / 2;
	point->ya = ft_calc_ya(ray);
	point->dis_x = point->xa;
	point->dis_y = point->ya;
	point->x = 0;
	point->y = 0;
	ray->vert_int = point;
	ray->vert_int = ft_vert_coordinates(ray, data, 1);
	while (1)
	{
		if (ft_check_wall(ray->vert_int, data))
			return ;
		ray->vert_int = ft_vert_coordinates(ray, data, 0);
		point->dis_x += point->xa;
		point->dis_y += point->ya;
	}
}
