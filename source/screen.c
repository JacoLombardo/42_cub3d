/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/08 16:20:02 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->res_x = 300;
	data->res_y = 200;
	data->bbp = 4;
}

int	init_screen(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->res_x, data->res_y, "Cube3D");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->res_x, data->res_y);
	if (data->img_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	// data->buff = mlx_get_data_addr(data->img_ptr, &frac->pixel_bits,
	// 		&frac->line_len, &frac->endian);
	return (0);
}

void	render_screen(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (j < data->res_y)
	{
		i = 0;
		while (i < data->res_x)
		{
			//calc_pixel(i, j, data);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr,
		0, 0);
}
