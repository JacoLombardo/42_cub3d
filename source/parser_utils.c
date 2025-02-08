/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:48:51 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 15:20:16 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_skip(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

void	ft_element_sort(t_map *map, char *copy, char element)
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

int	ft_filled(t_map *map)
{
	if (map->no && map->so && map->we && map->ea && map->c && map->f)
		return (1);
	else
		return (0);
}
