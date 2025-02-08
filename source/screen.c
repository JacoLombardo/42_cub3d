/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:13 by nboer             #+#    #+#             */
/*   Updated: 2025/02/08 14:30:22 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_screen(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (NULL)
	data->mlx_win = mlx_new_window(data->mlx, data->res_x, data->res_y, "Cube3D");
	mlx_loop(data->mlx_ptr);
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(frac->mlx_ptr);
		return (NULL);
	}
	data->img_ptr = mlx_new_image(frac->mlx_ptr, data->res_x, data->res_y);
	if (frac->img_ptr == NULL)
	{
		mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
		mlx_destroy_display(frac->mlx_ptr);
		free(frac->mlx_ptr);
		return (NULL);
	}
	// data->buff = mlx_get_data_addr(data->img_ptr, &frac->pixel_bits,
	// 		&frac->line_len, &frac->endian);
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
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr,
		0, 0);
}
