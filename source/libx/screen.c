/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/15 12:07:35 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_render_screen(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx, data->win);
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			//calc_pixel(i, j, data);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		0, 0);
}

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
