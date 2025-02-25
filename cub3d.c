/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:40 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/25 15:35:00 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_update_game(t_data *data)
{
	if (ft_events_keyboard(data))
		ft_update_image(data);
	return (0);
}

void	ft_cub3d(char *input)
{
	t_config	config;
	t_data		data;

	ft_config_init(&config);
	ft_parser(input, &config);
	ft_print_config(&config);
	ft_data_init(&data, &config);
	ft_libx_init(&data);
	ft_events_init(&data);
	ft_textures_init(&data);
	ft_update_image(&data);
	mlx_loop_hook(data.mlx, ft_update_game, &data);
	mlx_loop(data.mlx);
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
