/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:45:26 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/18 16:32:45 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	ft_free_rays(t_ray **rays)
{
	int	i;

	i = 0;
	while (rays[i])
	{
		if (rays[i]->hori_int)
			free(rays[i]->hori_int);
		if (rays[i]->vert_int)
			free(rays[i]->vert_int);
		free(rays[i]);
		i++;
	}
	free(rays);
}

void	ft_free_data(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->plane)
		free(data->plane);
	if (data->rays)
		ft_free_rays(data->rays);
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
