/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:11:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/19 19:07:29 by nboer            ###   ########.fr       */
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
		if (ft_get_tan(ray->angle) > 0.0001)
		{
			ray->hori_int->x = data->player->pos_x + (data->player->pos_y
					- ray->hori_int->y) / ft_get_tan(ray->angle);
		}
		else
			ray->hori_int->x = data->player->pos_x;
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
		if (ft_get_tan(ray->angle) > 0.0001)
		{
			ray->vert_int->y = data->player->pos_y + (data->player->pos_x
					- ray->vert_int->x) / ft_get_tan(ray->angle);
		}
		else
			ray->vert_int->y = data->player->pos_y;
	}
	else
	{
		ray->vert_int->y += ray->vert_int->ya;
		ray->vert_int->x += ray->vert_int->xa;
	}
}

void	ft_set_intersect(t_intersect *intersection, t_ray *ray, char type)
{
	if (type == 'h')
	{
		intersection->xa = GRID / ft_get_tan(ray->angle);
		if (ray->dir_y < 0)
			intersection->ya = -GRID;
		else
			intersection->ya = GRID;
	}
	else
	{
		intersection->ya = GRID * ft_get_tan(ray->angle);
		if (ray->dir_x < 0)
			intersection->xa = -GRID;
		else
			intersection->xa = GRID;
	}
	intersection->type = type;
	intersection->oor = 0;
	intersection->x = 0;
	intersection->y = 0;
}

void	ft_hori_intersection(t_ray *ray, t_data *data)
{
	t_intersect	*intersection;

	intersection = (t_intersect *)malloc(1 * sizeof(t_intersect));
	if (!intersection)
		ft_game_cleanup(data, "malloc");
	ray->hori_int = intersection;
	ft_set_intersect(ray->hori_int, ray, 'h');
	printf("xa: %f, ya: %f\n", ray->hori_int->xa, ray->hori_int->ya);
	ft_hori_inter_coord(ray, data, 1);
	while (1)
	{
		if (ft_check_wall(ray->hori_int, data))
			return ;
		ft_hori_inter_coord(ray, data, 0);
	}
}

void	ft_vert_intersection(t_ray *ray, t_data *data)
{
	t_intersect	*intersection;

	intersection = (t_intersect *)malloc(1 * sizeof(t_intersect));
	if (!intersection)
		ft_game_cleanup(data, "malloc");
	ray->vert_int = intersection;
	ft_set_intersect(ray->vert_int, ray, 'v');
	printf("xa: %f, ya: %f\n", ray->vert_int->xa, ray->vert_int->ya);
	ft_vert_inter_coord(ray, data, 1);
	while (1)
	{
		if (ft_check_wall(ray->vert_int, data))
			return ;
		ft_vert_inter_coord(ray, data, 0);
	}
}
