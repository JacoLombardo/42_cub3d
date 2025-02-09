/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:05:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 12:28:37 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_config(t_config *config)
{
	int	i;

	i = 0;
	if (config->no)
		free(config->no);
	if (config->so)
		free(config->so);
	if (config->we)
		free(config->we);
	if (config->ea)
		free(config->ea);
	if (config->c)
		free(config->c);
	if (config->f)
		free(config->f);
	ft_free_tab(config->map);
	free(config->player);
}

void	ft_parser_cleanup(t_config *config, char *line, int fd, char *type)
{
	if (ft_strcmp(type, "malloc"))
		write(2, "[Error] Malloc fail\n", 21);
	else if (ft_strcmp(type, "map"))
		write(2, "[Error] Invalid map\n", 21);
	if (config)
		ft_free_config(config);
	if (line)
		free(line);
	if (fd > 0)
		close(fd);
	exit(1);
}
