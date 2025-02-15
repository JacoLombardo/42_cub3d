/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:40 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/15 16:52:56 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_cub3d(char *input)
{
	t_config	config;
	t_data		data;

	// ft_config_init(&config);
	// ft_parser(input, &config);
	//ft_print_config(&config);
	ft_data_init(&data, &config);
	// ft_init_rays(&data);
	// ft_create_img(&config, &data);
	ft_render_screen(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.image->img, 0, 0);
	mlx_loop(data.mlx);

	/* ft_create_img(matrix, size, &image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, ft_handle_hooks, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
	mlx_loop(vars.mlx); */
	ft_free_data(&data);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_cub3d(argv[1]);
	else if (argc < 2)
		write(2, "[ERROR] Too few parameters, try ./cub3d [MAP NAME.cub]\n",
			55);
	else
		write(2, "[ERROR] Too many parameters, try ./cub3d [MAP NAME.cub]\n",
			56);
	return (0);
}
