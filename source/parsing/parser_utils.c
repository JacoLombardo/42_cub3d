/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:48:51 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/27 14:11:58 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_skip(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

void	ft_element_sort(t_config *config, char *copy, char element)
{
	if (element == 'N')
		config->no = copy;
	else if (element == 'S')
		config->so = copy;
	else if (element == 'W')
		config->we = copy;
	else if (element == 'E')
		config->ea = copy;
	else if (element == 'F')
		config->f = ft_format_color(copy, config);
	else if (element == 'C')
		config->c = ft_format_color(copy, config);
}

int	ft_strlen2(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i] && line[i] != '\n' && line[i] != ' ')
	{
		i++;
		len++;
	}
	return (len);
}

int	ft_filled(t_config *config)
{
	if (config->no && config->so && config->we && config->ea && config->c != -1
		&& config->f != -1)
		return (1);
	else
		return (0);
}

/* ft_check_n_player checks if the map is invalid (if contains chars not allowed) and also if there is the player in it,
	adding and extra check if the player was already set before */

int	ft_check_n_player(t_config *config, char **map, int len)
{
	int	i;

	i = 0;
	while (map[len][i])
	{
		if (map[len][i] == '1' || map[len][i] == '0' || map[len][i] == ' ')
			i++;
		else if (map[len][i] == 'N' || map[len][i] == 'S' || map[len][i] == 'W'
			|| map[len][i] == 'E')
		{
			if (config->player->pos_x == -1)
			{
				/* config->player->pos_x = (i + 0.5) * GRID;
				config->player->pos_y = (len + 0.5) * GRID; */
				config->player->pos_x = i * GRID;
				config->player->pos_y = len * GRID;
				ft_set_player_dir(map[len][i], config->player);
				map[len][i] = '0';
			}
			else
				return (1);
			i++;
		}
		else
			return (1);
	}
	return (0);
}
