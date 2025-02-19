/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/02/19 14:07:33 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int get_wall_height(double ray_distance)
{
	if (ray_distance <= 0.1)
		ray_distance = 0.1;
	return ((int) (HEIGHT / ray_distance));
}

void	ft_print_wall(t_intersect *wall_int, t_ray *ray, t_data *data)
{
	int	pix_y;
	int	wall_height;
	double	dis;

	printf("dis_x = %f\n", ray->vert_int->dis_x);
	printf("dis_y = %f\n\n", ray->vert_int->dis_x);
	dis = sqrt((wall_int->dis_x * wall_int->dis_x) + (wall_int->dis_y * wall_int->dis_y));
	wall_height = get_wall_height(dis);
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		calc_pixel(data, pix_y, ray->pixel, wall_height);
		pix_y++;
	}
}

// void ft_textures_init(t_data *data)
// {
// 	t_texture	*tex;

// 	tex = (t_texture *)malloc(1 * sizeof(t_texture));
// 	if (!tex)
// 		ft_game_cleanup(&data, "texture");
// 	tex->img = mlx_xpm_file_to_image(data->mlx, "includes/assets/wall.xpm",
// 			&(tex->width), &(tex->height));
// 	tex->addr = mlx_get_data_addr(tex->img, tex->bpp, tex->line_length, tex->endian);
// 	data->texture = tex;
// }
