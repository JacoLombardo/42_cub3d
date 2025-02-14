/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/14 15:16:07 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_wall(t_ray *ray, t_data *data, double x, double y)
{
	
}

void	ft_cast_ray(t_ray *ray, t_data *data, double xa, double ya)
{
	double	x_new;
	double	y_new;

	x_new = xa;
	y_new = ya;

	while (1)
	{
		if (ft_check_wall(ray, data, x_new, y_new))
			break ;
		x_new += xa;
		y_new += ya;
	}
}

void	ft_init_ray(double pos_x, double pos_y, t_data *data)
{
	int		i;
	double	start_angle;
	t_ray	**rays;
	t_ray	*temp;

	i = 0;
	rays = (t_ray **)malloc(WIDTH * sizeof(t_ray *));
	while (i < WIDTH)
	{
		temp = (t_ray *)malloc(1 * sizeof(t_ray));
		temp->angle = start_angle + (data->ray_angle * i);
		rays[i] = temp;
		// double cameraX = 2 * x / double(w) - 1;
		// double rayDirX = dirX + planeX * cameraX;
		// double rayDirY = dirY + planeY * cameraX;
		ft_cast_ray(rays[i], data, ft_calc_xa(rays[i]), ft_calc_ya(rays[i]));
		i++;
	}
}
