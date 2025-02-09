/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:13:48 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 11:33:10 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			ft_parser_cleanup(config, line, fd);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (!ft_add(config, line, ft_skip(line, i + 1), line[i]))
			ft_parser_cleanup(config, line, fd);
	}
}

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
		ft_parser_cleanup(config, line, fd);
	if (line[line_len - 1] == '\n')
		config->map[len - 1] = ft_strndup(line, line_len - 1);
	else
		config->map[len - 1] = ft_strdup(line);
	if (!config->map[len - 1])
		ft_parser_cleanup(config, line, fd);
	config->map[len] = NULL;
}

void	ft_handle_line(t_config *config, char *line, int fd)
{
	int	i;

	i = 0;
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
		ft_parser_cleanup(config, NULL, fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_handle_line(config, line, fd);
		free(line);
	}
	close(fd);
	ft_map_check(ft_map_clone(config), config);
	return (config);
}
