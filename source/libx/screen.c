/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/23 17:16:08 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_pixel(int side, t_data *data, int posY, int posX, int wall_height)
{
	int	wall_top;
	int	wall_bot;
	int color = 0;
	t_texture *tex;
	
	tex = data->tex;
	if (!tex)
		printf("texture not assigned to tex in calc pixel"); // DEBUG
	wall_top = (HEIGHT / 2) + (wall_height / 2);
	wall_bot = (HEIGHT / 2) - (wall_height / 2);
	if (posY < wall_bot)
		my_pixel_put(data, posY, posX, LIGHTBLUE); // FLOOR
	else if (posY > wall_top)
		my_pixel_put(data, posY, posX, BLUE); // CEILING
	else
	{
		tex->texY = (int)(((posY - wall_bot) / (double)wall_height) * tex->height);
		color = *(int *)(tex->addr + (tex->texY * tex->line_length + tex->texX * (tex->bpp / 8)));
		if (side)
			color = darken_color(color, 0.6);
		my_pixel_put(data, posY, posX, color);
	}
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
