/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:05:14 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/13 16:39:16 by jalombar         ###   ########.fr       */
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
	if (config->player)
		free(config->player);
}

void	ft_free_data(t_data *data)
{
	if (data->image->img)
		mlx_destroy_image(data->mlx, data->image->img);
	if (data->image)
		free(data->image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	ft_parser_cleanup(t_config *config, char *line, int fd, char *type)
{
	if (!ft_strcmp(type, "malloc"))
		ft_putendl_fd("[Error] Malloc fail", 2);
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

void	ft_libx_cleanup(t_data *data, t_config *config)
{
	ft_putendl_fd("[Error] Minilibx init failed", 2);
	ft_free_data(data);
	ft_free_config(config);
	exit(1);
}
