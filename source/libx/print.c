/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/02/19 18:10:43 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int get_wall_height(double ray_distance)
{
	if (ray_distance <= 0.1)
		ray_distance = 0.1;
	return ((int) (HEIGHT / ray_distance * 4));
}

void	ft_print_wall(char closest, t_intersect *wall_int, t_ray *ray, t_data *data)
{
	int		pix_y;
	int		wall_height;
	double	dis;
	
	if (closest == 'v') // closest intersection is vertical
		ray->dis_perp = fabs((wall_int->x - data->player->pos_x) / ray->dir_x);
	if (closest == 'h') // closest intersection is horizontal
		ray->dis_perp = fabs((wall_int->y - data->player->pos_y) / ray->dir_y);
	dis = wall_int->dis;
	wall_height = get_wall_height(ray->dis_perp);
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
// 		ft_game_cleanup(&data, "texture"); //<- needs update
// 	tex->img = mlx_xpm_file_to_image(data->mlx, "includes/assets/wall.xpm",
// 			&(tex->width), &(tex->height));
// 	tex->addr = mlx_get_data_addr(tex->img, tex->bpp, tex->line_length, tex->endian);
// 	data->texture = tex;
// }
