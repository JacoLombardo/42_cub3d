/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/25 14:25:36 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_pixel(int side, t_data *data, int posY, int posX, int wall_height)
{
	int			color;
	int			wall_top;
	int			wall_bot;
	t_texture	*tex;

	color = 0;
	tex = data->tex;
	if (!tex)
		printf("texture not assigned to tex in calc pixel\n"); // DEBUG
	wall_top = (HEIGHT / 2) + (wall_height / 2);
	wall_bot = (HEIGHT / 2) - (wall_height / 2);
	if (posY < wall_bot)
		my_pixel_put(data, posY, posX, data->config->f); // FLOOR
	else if (posY > wall_top)
		my_pixel_put(data, posY, posX, data->config->c); // CEILING
	else
	{
		tex->y = (int)(((posY - wall_bot) / (double)wall_height) * tex->height);
		color = *(int *)(tex->addr + (tex->y * tex->line_length + tex->x * (tex->bpp / 8)));
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
