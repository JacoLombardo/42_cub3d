/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 13:01:06 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_pixel(int side, t_data *data, int posY, int posX, int wall_height)
{
	int	wall_top;
	int	wall_bot;
	double factor;

	wall_top = (HEIGHT / 2) + (wall_height / 2);
	wall_bot = (HEIGHT / 2) - (wall_height / 2);
	if (posY < wall_bot)
		my_pixel_put(data, posY, posX, BLUE); // FLOOR
	else if (posY > wall_top)
		my_pixel_put(data, posY, posX, GREEN); // CEILING
	else
	{
		factor = 1;
		if (side)
		// if (data->player->mv_forward)
			factor = 1.5;
		my_pixel_put(data, posY, posX, darken_color(RED, factor)); // WALL
	}
		// make color brightness distinction between walls up/down and left/right to read better
}

void	my_pixel_put(t_data *data, int posY, int posX, int color)
{
	int	offset;

	offset = (posY * data->image->line_length) + (posX * (data->image->bpp
				/ 8));
	*(unsigned int *)(data->image->addr + offset) = color;
}

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
