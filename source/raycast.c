/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/13 16:49:06 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_ray(double pos_x, double pos_y, t_data *data)
{
	t_ray	*rays;
	int		i;

	rays = (t_ray *)malloc(1 * sizeof(t_ray));
	i = 0;
	while (i < data->res_x)
	{
		// double cameraX = 2 * x / double(w) - 1;
		// double rayDirX = dirX + planeX * cameraX;
		// double rayDirY = dirY + planeY * cameraX;
		ft_cast_ray();
		i++;
	}
}

void	ft_cast_ray(void)
{
}
