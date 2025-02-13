/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/09 17:14:42 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
 
void	init_ray(double pos_x, double pos_y, t_data *data)
{
	t_ray *rays;
	
	rays = malloc(sizeof(t_ray) * data->res_x);
	int i;

	i = 0;
	while (i < data->res_x)
	{
		// double cameraX = 2 * x / double(w) - 1;
		// double rayDirX = dirX + planeX * cameraX;
		// double rayDirY = dirY + planeY * cameraX;
		cast_ray();
		i++;
	}
}

void	cast_ray()
{

}
