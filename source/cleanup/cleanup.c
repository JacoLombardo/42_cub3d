/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:05:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/18 16:29:56 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_parser_cleanup(t_config *config, char *line, int fd, char *type)
{
	if (!ft_strcmp(type, "malloc"))
		ft_putendl_fd("[Error] Malloc failed", 2);
	else if (!ft_strcmp(type, "map"))
		ft_putendl_fd("[Error] Invalid map", 2);
	if (config)
		ft_free_config(config);
	if (line)
		free(line);
	if (fd > 0)
		close(fd);
	exit(1);
}

void	ft_init_cleanup(t_data *data, t_config *config, char *type)
{
	if (!ft_strcmp(type, "libx"))
		ft_putendl_fd("[Error] Minilibx init failed", 2);
	else if (!ft_strcmp(type, "malloc"))
		ft_putendl_fd("[Error] Malloc failed", 2);
	if (data)
		ft_free_data(data);
	else if (config)
		ft_free_config(config);
	exit(1);
}

void	ft_game_cleanup(t_data *data, char *type)
{
	if (!ft_strcmp(type, "malloc"))
		ft_putendl_fd("[Error] Malloc failed", 2);
	else if (!ft_strcmp(type, "ray"))
		ft_putendl_fd("[Error] Ray failed", 2);
	ft_free_data(data);
	exit(1);
}
