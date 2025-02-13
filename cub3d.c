/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:40 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 17:18:47 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	test(t_data *data)
{
	int			x;
	int			y;

	x = 100;
	y = 0;
	while (y < 300)
	{
		ft_mlx_pixel_put(data->image, x, y, 16777215);
		/* x = 0;
		while (y < (int)ft_strlen(config->map[y]))
		{
			if (config->map[y][x] == '0' || config->map[y][x] == '1')
				ft_mlx_pixel_put(data->image, x, y, 16777215);
			x++;
		} */
		y++;
	}
}

void	ft_draw_square(t_image *image, int x_start, int y_start, int size, int color)
{
	int	x;
	int	y;

	y = y_start;
	while (y < y_start + size && y < HEIGHT)
	{
		x = x_start;
		while (x < x_start + size && x < WIDTH)
		{
			ft_mlx_pixel_put(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_cub3d(char *input)
{
	t_config	config;
	t_data		data;

	ft_config_init(&config);
	ft_parser(input, &config);
	ft_print_config(&config);
	ft_data_init(&data);
	if (ft_libx_init(&data))
	{
		ft_free_config(&config);
		return ;
	}
	ft_create_img(&config, &data);
	//ft_draw_square(data.image, 50, 50, 100, 0xFFFFFF);
	mlx_put_image_to_window(data.mlx, data.win, data.image->img, 0, 0);
	mlx_loop(data.mlx);

	/* ft_create_img(matrix, size, &image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, ft_handle_hooks, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
	mlx_loop(vars.mlx); */
	
	// render_screen(&data);
	// mlx_loop(structname.mlx_ptr);
	// mlx_clean(&structrname);
	// exit(EXIT_SUCCESS);
	ft_free_config(&config);
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
