/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/18 10:31:13 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_pixel(t_data *data, int posY, int posX, int wall_height)
{
	int	remain_pix;

	remain_pix = HEIGHT - wall_height;
	if (posY < (remain_pix / 2))
		my_pixel_put(data, posY, posX, BLUE); // FLOOR
	else if (posY > (HEIGHT / 2) + (remain_pix / 2))
		my_pixel_put(data, posY, posX, GREEN); // CEILING
	else
		my_pixel_put(data, posY, posX, RED); // WALL
}

void	ft_render_screen(t_data *data)
{
	int	i;
	int	j;
	int	wall_y;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx, data->win);
	while (j < WIDTH)
	{
		i = 0;
		wall_y = get_wall_height(2); // should pass data->rays[i]->dis
		while (i < HEIGHT)
		{
			calc_pixel(data, i, j, wall_y);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
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
