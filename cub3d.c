/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:40 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 16:14:16 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_cub3d(char *input)
{
	t_map	map;
	t_data	data;
	
	ft_map_init(&map);
	ft_parser(input, &map);
	ft_print_result(&map);
	init_data(&data);
	init_screen(&data);
	init_events(&data);
	mlx_loop(data.mlx_ptr);
	// render_screen(&data);
	// mlx_loop(structname.mlx_ptr);
	// mlx_clean(&structrname);
	// exit(EXIT_SUCCESS);
	ft_free_map(&map);
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
