/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:40 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 14:08:15 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_print_result(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("NO: %s\n", map->no);
	ft_printf("SO: %s\n", map->so);
	ft_printf("WE: %s\n", map->we);
	ft_printf("EA: %s\n", map->ea);
	ft_printf("Ceiling: %s\n", map->c);
	ft_printf("Floor: %s\n", map->f);
	ft_printf("\nMAP: \n\n");
	while (map->map[i])
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}

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
	t_data	data;
	
	ft_map_init(&map);
	ft_parser(input, &map);
	ft_print_result(&map);
	init_screen(&data);
	// events_init(&structname);
	render_screen(&data);
	// mlx_loop(structname.mlx_ptr);
	// mlx_clean(&structrname);
	// exit(EXIT_SUCCESS);
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
