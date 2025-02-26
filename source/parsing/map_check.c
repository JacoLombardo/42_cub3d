/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:12:51 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/26 14:39:19 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_format_color(char *str, t_config *config)
{
	int		r;
	int		g;
	int		b;
	char	**temp;

	temp = ft_split(str, ',');
	if (!temp)
		ft_parser_cleanup(config, NULL, -1, "malloc");
	r = ft_atoi(temp[0]);
	g = ft_atoi(temp[1]);
	b = ft_atoi(temp[2]);
	ft_free_tab(temp);
	free(str);
	return ((r << 16) | (g << 8) | b);
}

char	**ft_map_clone(t_config *config)
{
	int		i;
	int		height;
	char	**new_map;

	i = 0;
	height = ft_tab_len(config->map);
	new_map = (char **)malloc((height + 1) * sizeof(char *));
	if (!new_map)
		ft_parser_cleanup(config, NULL, -1, "malloc");
	while (i < height)
	{
		new_map[i] = ft_strdup(config->map[i]);
		if (!new_map[i])
		{
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			ft_parser_cleanup(config, NULL, -1, "malloc");
		}
		i++;
	}
	new_map[height] = NULL;
	return (new_map);
}


int	ft_elements_check(t_config *config, char **map)
{
	int	x;
	int	y;

	x = config->player->pos_x / GRID;
	y = config->player->pos_y / GRID;
	if (config->c == -1 || config->f == -1)
		return (1);
	else if (map[y - 1][x] == ' ' || map[y][x - 1] == ' ' || map[y
		+ 1][x] == ' ' || map[y][x + 1] == ' ')
		return (1);
	else
		return (0);
}

void	ft_flood_fill(char **map, int x, int y, t_config *config)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'F')
		return ;
	if (map[y][x] == ' ')
	{
		ft_free_tab(map);
		ft_parser_cleanup(config, NULL, -1, "map");
	}
	map[y][x] = 'F';
	ft_flood_fill(map, x + 1, y, config);
	ft_flood_fill(map, x - 1, y, config);
	ft_flood_fill(map, x, y + 1, config);
	ft_flood_fill(map, x, y - 1, config);
}

void	ft_map_check(char **map, t_config *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_elements_check(config, map) || config->player->pos_x == -1)
	{
		ft_free_tab(map);
		ft_parser_cleanup(config, NULL, -1, "map");
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				ft_flood_fill(map, j, i, config);
			j++;
		}
		i++;
	}
	ft_free_tab(map);
}
