/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:13:48 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/16 16:46:38 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_config	*ft_add(t_config *config, char *line, int i, char element)
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
	ft_element_sort(config, copy, element);
	return (config);
}

void	ft_elements(t_config *config, char *line, int fd)
{
	int	i;

	i = 0;
	if (line[i] == ' ')
		i = ft_skip(line, i);
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
	{
		if (!ft_add(config, line, ft_skip(line, i + 2), line[i]))
			ft_parser_cleanup(config, line, fd, "malloc");
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (!ft_add(config, line, ft_skip(line, i + 1), line[i]))
			ft_parser_cleanup(config, line, fd, "malloc");
	}
}

/* ft_map first checks how many rows of map we have parsed already,
	to calcuale the len. Then reallocate the memory to add one more row and duplicate the line,
	while checking if the player is in the line. */

void	ft_map(t_config *config, char *line, int fd)
{
	int	len;
	int	line_len;

	len = 1;
	line_len = ft_strlen(line);
	while (config->map[len - 1])
		len++;
	config->map = ft_realloc(config->map, (len * sizeof(char **)), ((len + 1)
				* sizeof(char **)));
	if (!config->map)
		ft_parser_cleanup(config, line, fd, "malloc");
	if (line[line_len - 1] == '\n')
		config->map[len - 1] = ft_strndup(line, line_len - 1);
	else
		config->map[len - 1] = ft_strdup(line);
	config->map[len] = NULL;
	if (!config->map[len - 1])
		ft_parser_cleanup(config, line, fd, "malloc");
	else if (ft_check_n_player(config, config->map, len - 1))
		ft_parser_cleanup(config, line, fd, "map");
}

/* ft_handle_line checks if the config elements are not filled,
	and in that case keeps filling them, otherwise it starts parsing the map */

void	ft_handle_line(t_config *config, char *line, int fd)
{
	// int	i;

	// i = 0
	if (line[0] == '\n')
		return ;
	if (!ft_filled(config))
		ft_elements(config, line, fd);
	else
		ft_map(config, line, fd);
}

t_config	*ft_parser(char *input, t_config *config)
{
	int		fd;
	char	*line;

	fd = open(input, O_RDONLY);
	if (fd < 0)
		ft_parser_cleanup(config, NULL, fd, "map");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_handle_line(config, line, fd);
		free(line);
	}
	close(fd);
	if (!ft_filled(config) || !config->map[0])
		ft_parser_cleanup(config, line, fd, "map");
	ft_map_check(ft_map_clone(config), config);
	return (config);
}
