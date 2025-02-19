/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:34:11 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/19 14:09:13 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_wall(t_intersect *intersection, t_data *data)
{
	int	x;
	int	y;

	x = intersection->x / GRID;
	y = intersection->y / GRID;
	//printf("here x:%i, y: %i\n", x, y);
	if (x >= data->config->map_height || x < 0)
	{
		//printf("[Error] Out of reach\n");
		intersection->oor = 1;
		return (1);
	}
	else if (y >= (int)ft_strlen(data->config->map[x]) || y < 0)
	{
		//printf("[Error] Out of reach\n");
		intersection->oor = 1;
		return (1);
	}
	//printf("POS: x: %i, y: %i, x(pixel): %f, y(pixel): %f, value: %c\n", x, y, intersection->x, intersection->y, data->config->map[x][y]);
	if (data->config->map[x][y] && data->config->map[x][y] == '1')
	{
		//printf("WALL FOUND!\n");
		return (1);
	}
	else if (data->config->map[x][y] && data->config->map[x][y] == '0')
	{
		//printf("Wall not found\n");
		return (0);
	}
	else
	{
		//printf("[Error] Out of reach\n");
		intersection->oor = 1;
		return (1);
	}
}
