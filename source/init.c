/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:01:06 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 16:05:58 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_config	*ft_config_init(t_config *config)
{
	char		**map;
	t_player	*player;

	map = (char **)malloc(1 * sizeof(char *));
	if (!map)
		return (NULL);
	map[0] = NULL;
	config->map = map;
	player = (t_player *)malloc(1 * sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = -1;
	player->y = -1;
	player->direction = 'I';
	config->player = player;
	config->no = NULL;
	config->so = NULL;
	config->we = NULL;
	config->ea = NULL;
	config->c = NULL;
	config->f = NULL;
	return (config);
}

void	ft_data_init(t_data *data)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = NULL;
	image->addr = NULL;
	image->bbp = 0;
	image->line_length = 0;
	image->endian = 0;
	data->image = image;
	data->mlx = NULL;
	data->win = NULL;
}

void	ft_events_init(t_data *data)
{
	mlx_hook(data->win, DestroyNotify, 0, ft_event_close_win, data);
	mlx_key_hook(data->win, ft_events_keyboard, data);
	// mlx_mouse_hook(data->win_ptr, events_mouse_press, data);
}

int	ft_libx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cube3D");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
	}
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->image->img == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
	}
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bbp,
			&data->image->line_length, &data->image->endian);
	if (!data->image->addr)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
	}
	ft_events_init(data);
	// data->buff = mlx_get_data_addr(data->img, &frac->pixel_bits,
	// 		&frac->line_len, &frac->endian);
	return (0);
}
