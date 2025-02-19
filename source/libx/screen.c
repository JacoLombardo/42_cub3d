/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/19 11:54:05 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_pixel(t_data *data, int posY, int posX, int wall_height)
{
	int wall_top;
	int	wall_bot;
	
	wall_top = (HEIGHT / 2) + (wall_height / 2);
	wall_bot = (HEIGHT / 2) - (wall_height / 2);
	if (posY < wall_bot)
		my_pixel_put(data, posY, posX, BLUE); // FLOOR
	else if (posY > wall_top)
		my_pixel_put(data, posY, posX, GREEN); // CEILING
	else
		my_pixel_put(data, posY, posX, RED); // WALL
}

void	my_pixel_put(t_data *data, int posY, int posX, int color)
{
	int	offset;

	offset = (posY * data->image->line_length) + (posX * (data->image->bbp
				/ 8));
	*(unsigned int *)(data->image->addr + offset) = color;
}

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
