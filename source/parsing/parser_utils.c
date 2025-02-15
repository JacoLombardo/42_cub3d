/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:48:51 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/15 12:07:43 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_skip(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

void	ft_element_sort(t_config *map, char *copy, char element)
{
	if (element == 'N')
		map->no = copy;
	else if (element == 'S')
		map->so = copy;
	else if (element == 'W')
		map->we = copy;
	else if (element == 'E')
		map->ea = copy;
	else if (element == 'F')
		map->f = copy;
	else if (element == 'C')
		map->c = copy;
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

int	ft_filled(t_config *map)
{
	if (map->no && map->so && map->we && map->ea && map->c && map->f)
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
				config->player->pos_x = len;
				config->player->pos_y = i;
				config->player->orientation = map[len][i];
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
