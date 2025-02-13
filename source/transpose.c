/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:39:37 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 15:44:16 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**transpose_map(char **map)
{
	int		y, x;
	int		height = 0, width = 0;
	char	**new_map;

	// Get the height and max width of the map
	while (map[height])
	{
		int len = ft_strlen(map[height]);
		if (len > width)
			width = len;
		height++;
	}

	// Allocate new map
	new_map = (char **)malloc((width + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);

	// Allocate each row (now columns) and initialize with spaces
	for (x = 0; x < width; x++)
	{
		new_map[x] = (char *)malloc((height + 1) * sizeof(char));
		if (!new_map[x])
			return (NULL);

		for (y = 0; y < height; y++)
		{
			// Check if original map has this character
			if (map[y] && x < (int)ft_strlen(map[y]))
				new_map[x][y] = map[y][x];
			else
				new_map[x][y] = ' '; // Fill with space if out of bounds
		}
		new_map[x][height] = '\0'; // Null-terminate each row
	}

	new_map[width] = NULL; // Null-terminate the whole array
	return (new_map);
}
