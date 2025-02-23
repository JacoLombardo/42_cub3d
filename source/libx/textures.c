/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:23:17 by nboer             #+#    #+#             */
/*   Updated: 2025/02/23 17:54:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_textures_init(t_data *data)
{
	t_texture	*tex;

	tex = (t_texture *)malloc(1 * sizeof(t_texture));
	if (!tex)
	{
		printf("texture malloc failure\n");
		// ft_game_cleanup(&data, "texture"); //<- needs update
		return ; 
	}
	tex->img = mlx_xpm_file_to_image(data->mlx, "assets/textures/orca.xpm",
			&(tex->width), &(tex->height));
	if (!tex->img)
	{
		printf("texture not found\n");
		return ;
	}
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp), &(tex->line_length),
			&(tex->endian));
	if (!tex->addr)
	{
		printf("texture adress not found\n");
	}
	data->tex = tex;
}

void ft_calc_texture(t_ray *ray, t_data *data)
{
	double wallX;

	if (ray->side == 0)
		wallX = ray->hit_y;
	else
		wallX = ray->hit_x;
	wallX -= floor(wallX);
	data->tex->texX = (int)(wallX * (double)(data->tex->width));
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
		data->tex->texX = data->tex->width - data->tex->texX - 1;
}
