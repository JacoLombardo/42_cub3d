/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:01:06 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/18 16:00:59 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Init of both main structures and minilibx */

void	ft_config_init(t_config *config)
{
	char		**map;
	t_player	*player;

	map = (char **)malloc(1 * sizeof(char *));
	if (!map)
		ft_init_cleanup(NULL, config, "malloc");
	map[0] = NULL;
	config->map = map;
	player = (t_player *)malloc(1 * sizeof(t_player));
	if (!player)
		ft_init_cleanup(NULL, config, "malloc");
	player->pos_x = -1;
	player->pos_y = -1;
	player->dir_x = -1;
	player->dir_y = -1;
	player->orientation = 'I';
	config->player = player;
	config->no = NULL;
	config->so = NULL;
	config->we = NULL;
	config->ea = NULL;
	config->c = NULL;
	config->f = NULL;
}

void	ft_set_player_dir(t_player *player)
{
	if (player->orientation == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->view_angle = 90;
	}
	else if (player->orientation == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->view_angle = 270;
	}
	else if (player->orientation == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->dir_y = 180;
	}
	else if (player->orientation == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->dir_y = 0;
	}
}

void	ft_plane_init(t_data *data)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(1 * sizeof(t_plane));
	if (!plane)
		ft_init_cleanup(data, NULL, "malloc");
	plane->size = ft_get_tan(FOV / 2);
	plane->x = data->player->dir_x * plane->size;
	plane->y = data->player->dir_y * plane->size;
	data->plane = plane;
}

void	ft_data_init(t_data *data, t_config *config)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		ft_init_cleanup(data, NULL, "malloc");
	image->img = NULL;
	image->addr = NULL;
	image->bbp = 0;
	image->line_length = 0;
	image->endian = 0;
	data->image = image;
	data->mlx = NULL;
	data->win = NULL;
	data->ray_angle = (double)FOV / WIDTH;
	data->config = config;
	data->player = NULL;
	data->image = image;
	data->player = config->player;
	ft_set_player_dir(data->player);
	ft_plane_init(data);
}

void	ft_events_init(t_data *data)
{
	mlx_hook(data->win, DestroyNotify, 0, ft_event_close_win, data);
	mlx_key_hook(data->win, ft_events_keyboard, data);
	// mlx_mouse_hook(data->win_ptr, events_mouse_press, data);
}

void	ft_libx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_init_cleanup(data, NULL, "libx");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cube3D");
	if (data->win == NULL)
		ft_init_cleanup(data, NULL, "libx");
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->image->img == NULL)
		ft_init_cleanup(data, NULL, "libx");
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bbp,
			&data->image->line_length, &data->image->endian);
	if (!data->image->addr)
		ft_init_cleanup(data, NULL, "libx");
	ft_events_init(data);
}
