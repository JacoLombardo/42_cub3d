/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:40 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 13:51:35 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_map_init(t_map *map)
{
	char	**mapx;

	mapx = (char **)malloc(1 * sizeof(char *));
	mapx[0] = NULL;
	map->map = mapx;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->c = NULL;
	map->f = NULL;
}

void	ft_cub3d(char *input)
{
	t_map	map;

	ft_map_init(&map);
	ft_parser(input, &map);
	//ft_print_map(&map);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_cub3d(argv[1]);
	else if (argc < 2)
		write(2, "ERROR: Too few parameters, try ./cub3d [MAP NAME.cub]\n", 55);
	else
		write(2, "ERROR: Too many parameters, try ./cub3d [MAP NAME.cub]\n", 56);
	return (0);
}
