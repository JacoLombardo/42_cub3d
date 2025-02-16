/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:11:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/15 16:41:25 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_wall(t_intersect *intersection, t_data *data)
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

t_intersect	*ft_hori_coordinates(t_ray *ray, t_data *data, int first)
{
	int	dir_y;

	if (ray->dir_y < 0)
		dir_y = -1;
	else
		dir_y = GRID / 2;
	if (first)
	{
		ray->hori_int->y = ((floor(data->player->pos_y / GRID) * GRID)
				+ (dir_y)) / GRID;
		ray->hori_int->x = ((data->player->pos_x * GRID)
				+ (((data->player->pos_y * GRID) - (ray->hori_int->y * GRID))
					/ ft_get_tan(ray->angle))) / GRID;
	}
	else
	{
		ray->hori_int->y = ((ray->hori_int->y * GRID) + (ray->ya * GRID))
			/ GRID;
		ray->hori_int->x = ((ray->hori_int->x * GRID) + (ray->xa * GRID))
			/ GRID;
	}
	return (ray->hori_int);
}

t_intersect	*ft_vert_coordinates(t_ray *ray, t_data *data, int first)
{
	int	dir_x;

	if (ray->dir_x < 0)
		dir_x = -1;
	else
		dir_x = GRID / 2;
	if (first)
	{
		ray->vert_int->x = ((floor(data->player->pos_x) * GRID) + (dir_x))
			/ GRID;
		ray->vert_int->y = ((data->player->pos_y * GRID)
				+ (((data->player->pos_x * GRID) - (ray->vert_int->x * GRID))
					/ ft_get_tan(ray->angle))) / GRID;
	}
	else
	{
		ray->vert_int->y = ((ray->vert_int->y * GRID) + (ray->vert_int->ya
					* GRID)) / GRID;
		ray->vert_int->x = ((ray->vert_int->x * GRID) + (ray->vert_int->xa
					* GRID)) / GRID;
	}
	return (ray->vert_int);
}

void	ft_hori_intersection(t_ray *ray, t_data *data)
{
	t_intersect	*point;

	point = (t_intersect *)malloc(1 * sizeof(t_intersect));
	if (!point)
		return ;
	point->xa = ft_calc_xa(ray);
	point->ya = GRID / 2;
	printf("xa: %f, y: %f\n", point->xa, point->ya);
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
	t_intersect	*point;

	point = (t_intersect *)malloc(1 * sizeof(t_intersect));
	if (!point)
		return ;
	point->xa = GRID / 2;
	point->ya = ft_calc_ya(ray);
	printf("xa: %f, y: %f\n", point->xa, point->ya);
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
