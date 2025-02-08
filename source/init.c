/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:01:06 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 15:25:56 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map	*ft_map_init(t_map *map)
{
	char	**mapx;

	mapx = (char **)malloc(1 * sizeof(char *));
	if (!mapx)
		return (NULL);
	mapx[0] = NULL;
	map->map = mapx;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->c = NULL;
	map->f = NULL;
	return (map);
}

/* void	init_screen(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (NULL);
} */
