/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:13:48 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/07 15:02:55 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_add(t_map *map, char *line, int i, char element)
{
	int		j;
	int		len;
	char	*copy;

	j = 0;
	len = ft_strlen2(line, i);
	copy = (char *)malloc((len + 1) * sizeof(char));
	while (j < len)
	{
		copy[j] = line[i + j];
		j++;
	}
	copy[j] = '\n';
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

void	ft_elements(t_map *map, char *line, int *count)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i = ft_skip(line, i);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			ft_add(map, line, ft_skip(line, i + 2), line[i]);
		else if (line[i] == 'F' || line[i] == 'G')
			ft_add(map, line, ft_skip(line, i + 1), line[i]);
		i++;
	}
	*count++;
}

void	ft_map(t_map *map, char *line)
{
	
}

void	ft_handle_line(t_map *map, char *line, int *count)
{
	if (line[0] == '\n')
		return ;
	if (*count <= 6)
		ft_elements(map, line, count);
	else
		ft_map(map, line);
}

t_map	*ft_parser(char *map)
{
	int		fd;
	int		count;
	char	*line;
	t_map	map;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line;
		if (!line)
			break ;
		ft_handle_line(&map, line, &count);
	}
	close(fd);
}
