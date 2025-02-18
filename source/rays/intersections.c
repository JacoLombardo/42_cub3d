/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:11:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/18 16:33:26 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_hori_inter_coord(t_ray *ray, t_data *data, int first)
{
	int	dir_y;

	if (ray->dir_y < 0)
		dir_y = -1;
	else
		dir_y = GRID;
	if (first)
	{
		ray->hori_int->y = floor(data->player->pos_y / GRID) * GRID + dir_y;
		ray->hori_int->x = data->player->pos_x + (data->player->pos_y
				- ray->hori_int->y) / ft_get_tan(ray->angle);
		/* ray->hori_int->x = data->player->pos_x + (data->player->pos_y
				- ray->hori_int->y) * cos(ray->angle) / sin(ray->angle); */
	}
	else
	{
		ray->hori_int->y += ray->hori_int->ya;
		ray->hori_int->x += ray->hori_int->xa;
	}
}

void	ft_vert_inter_coord(t_ray *ray, t_data *data, int first)
{
	int	dir_x;

	if (ray->dir_x < 0)
		dir_x = -1;
	else
		dir_x = GRID;
	if (first)
	{
		ray->vert_int->x = floor(data->player->pos_x / GRID) * GRID + dir_x;
		ray->vert_int->y = data->player->pos_y + (data->player->pos_x
				- ray->vert_int->x) / ft_get_tan(ray->angle);
		/* ray->vert_int->y = data->player->pos_y + (data->player->pos_x
				- ray->vert_int->x) * sin(ray->angle) / cos(ray->angle); */
	}
	else
	{
		ray->vert_int->y += ray->vert_int->ya;
		ray->vert_int->x += ray->vert_int->xa;
	}
}

t_intersect	*ft_set_intersect(t_ray *ray, t_data *data, char type)
{
	t_intersect	*point;

	point = (t_intersect *)malloc(1 * sizeof(t_intersect));
	if (!point)
		ft_game_cleanup(data, "malloc");
	if (type == 'h')
	{
		//point->xa = GRID * cos(ray->angle);
		point->xa = GRID / ft_get_tan(ray->angle);
		if (ray->dir_y < 0)
			point->ya = -GRID;
		else
			point->ya = GRID;
	}
	else
	{
		//point->ya = GRID * sin(ray->angle);
		point->ya = GRID * ft_get_tan(ray->angle);
		if (ray->dir_x < 0)
			point->xa = -GRID;
		else
			point->xa = GRID;
	}
	point->x = 0;
	point->y = 0;
	return (point);
}

void	ft_hori_intersection(t_ray *ray, t_data *data)
{
	ray->hori_int = ft_set_intersect(ray, data, 'h');
	ray->hori_int->dis_x = ray->hori_int->xa;
	ray->hori_int->dis_y = ray->hori_int->ya;
	printf("xa: %f, ya: %f\n", ray->hori_int->xa, ray->hori_int->ya);
	ft_hori_inter_coord(ray, data, 1);
	while (1)
	{
		if (ft_check_wall(ray->hori_int, data))
			return ;
		ft_hori_inter_coord(ray, data, 0);
		ray->hori_int->dis_x += ray->hori_int->xa;
		ray->hori_int->dis_y += ray->hori_int->ya;
	}
}

void	ft_vert_intersection(t_ray *ray, t_data *data)
{
	ray->vert_int = ft_set_intersect(ray, data, 'v');
	ray->vert_int->dis_x = ray->vert_int->xa;
	ray->vert_int->dis_y = ray->vert_int->ya;
	printf("xa: %f, ya: %f\n", ray->vert_int->xa, ray->vert_int->ya);
	ft_vert_inter_coord(ray, data, 1);
	while (1)
	{
		if (ft_check_wall(ray->vert_int, data))
			return ;
		ft_vert_inter_coord(ray, data, 0);
		ray->vert_int->dis_x += ray->vert_int->xa;
		ray->vert_int->dis_y += ray->vert_int->ya;
	}
}
