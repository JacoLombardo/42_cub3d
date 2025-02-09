/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:01:06 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 12:26:50 by jalombar         ###   ########.fr       */
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

/* void	init_screen(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (NULL);
} */
