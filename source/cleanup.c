/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:05:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 15:26:49 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->c)
		free(map->c);
	if (map->f)
		free(map->f);
	if (map->map[0])
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
	}
	free(map->map);
}

void	ft_parser_cleanup(t_map *map, char *line, int fd)
{
	perror("[Error] Malloc fail");
	if (map)
		ft_free_map(map);
	if (line)
		free(line);
	close(fd);
	exit(1);
}
