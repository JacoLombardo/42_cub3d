/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:13:48 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 15:27:48 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map	*ft_add(t_map *map, char *line, int i, char element)
{
	int		j;
	int		len;
	char	*copy;

	j = 0;
	len = ft_strlen2(line, i);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	while (j < len)
	{
		copy[j] = line[i + j];
		j++;
	}
	copy[j] = '\0';
	ft_element_sort(map, copy, element);
	return (map);
}

void	ft_elements(t_map *map, char *line, int fd)
{
	int	i;

	i = 0;
	if (line[i] == ' ')
		i = ft_skip(line, i);
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
	{
		if (!ft_add(map, line, ft_skip(line, i + 2), line[i]))
			ft_parser_cleanup(map, line, fd);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (!ft_add(map, line, ft_skip(line, i + 1), line[i]))
			ft_parser_cleanup(map, line, fd);
	}
}

void	ft_map(t_map *map, char *line, int fd)
{
	int	len;
	int	line_len;

	len = 1;
	line_len = ft_strlen(line);
	while (map->map[len - 1])
		len++;
	map->map = ft_realloc(map->map, (len * sizeof(char **)), ((len + 1)
				* sizeof(char **)));
	if (!map->map)
		ft_parser_cleanup(map, line, fd);
	if (line[line_len - 1] == '\n')
		map->map[len - 1] = ft_strndup(line, line_len - 1);
	else
		map->map[len - 1] = ft_strdup(line);
	if (!map->map[len - 1])
		ft_parser_cleanup(map, line, fd);
	map->map[len] = NULL;
}

void	ft_handle_line(t_map *map, char *line, int fd)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return ;
	if (!ft_filled(map))
		ft_elements(map, line, fd);
	else
		ft_map(map, line, fd);
}

void	ft_parser(char *input, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(input, O_RDONLY);
	if (fd < 0)
		ft_parser_cleanup(map, NULL, fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_handle_line(map, line, fd);
		free(line);
	}
	close(fd);
}
