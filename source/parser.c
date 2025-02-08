/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:13:48 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 12:38:20 by jalombar         ###   ########.fr       */
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
	copy[j] = '\0';
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
	if (line[i] == ' ')
		i = ft_skip(line, i);
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		ft_add(map, line, ft_skip(line, i + 2), line[i]);
	else if (line[i] == 'F' || line[i] == 'C')
		ft_add(map, line, ft_skip(line, i + 1), line[i]);
	(*count)++;
}

void	ft_map(t_map *map, char *line)
{
	int	len;
	int	line_len;

	len = 1;
	line_len = ft_strlen(line);
	while (map->map[len - 1])
		len++;
	map->map = ft_realloc(map->map, (len * sizeof(char **)), ((len + 1)
				* sizeof(char **)));
	if (line[line_len - 1] == '\n')
		map->map[len - 1] = ft_strndup(line, line_len - 1);
	else
		map->map[len - 1] = ft_strdup(line);
	map->map[len] = NULL;
}

int	ft_filled(t_map *map)
{
	if (map->no && map->so && map->we && map->ea && map->c && map->f)
		return (1);
	else
		return (0);
}

void	ft_handle_line(t_map *map, char *line, int *count)
{
	if (line[0] == '\n')
		return ;
	if (!ft_filled(map))
		ft_elements(map, line, count);
	else
		ft_map(map, line);
}

void	ft_parser(char *input, t_map *map)
{
	int		fd;
	int		count;
	char	*line;

	// char	**mapx;
	count = 0;
	/* mapx = (char **)malloc(1 * sizeof(char *));
	mapx[0] = NULL;
	map->map = mapx; */
	fd = open(input, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_handle_line(map, line, &count);
	}
	close(fd);
}
