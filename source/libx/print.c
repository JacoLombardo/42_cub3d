/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/02/25 15:29:22 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_texture	*ft_get_face(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (data->texs[2]); // Wall facing west
		else
			return (data->texs[3]); // Wall facing east
	}
	else
	{
		if (ray->dir_y > 0)
			return (data->texs[0]); // Wall facing north
		else
			return (data->texs[1]); // Wall facing south
	}
}

void	ft_calc_pixel(t_seg *seg, t_texture *tex, t_data *data)
{
	int	color;

	color = 0;
	if (seg->y < seg->wall_bot)
		my_pixel_put(data, seg->y, seg->x, data->config->f); // Floor
	else if (seg->y > seg->wall_top)
		my_pixel_put(data, seg->y, seg->x, data->config->c); // Ceiling
	else
	{
		tex->y = (int)(((seg->y - seg->wall_bot) / (double)seg->wall_height)
				* tex->height);
		color = *(int *)(tex->addr + (tex->y * tex->line_length + tex->x
					* (tex->bpp / 8)));
		my_pixel_put(data, seg->y, seg->x, color);
	}
}

void	ft_print_wall(t_ray *ray, t_data *data)
{
	int			pix_y;
	t_seg		seg;
	t_texture	*tex;

	seg.wall_height = (int)(WALL_HEIGHT / (ray->perp_wall_dist) * WIDTH)
		*SCALING_FACTOR;
	seg.wall_top = (HEIGHT / 2) + (seg.wall_height / 2);
	seg.wall_bot = (HEIGHT / 2) - (seg.wall_height / 2);
	tex = ft_get_face(ray, data);
	seg.x = ray->pixel;
	ft_calc_texture(ray, tex, data);
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		seg.y = pix_y;
		ft_calc_pixel(&seg, tex, data);
		pix_y++;
	}
}

int	darken_color(int color, double factor)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	return ((r << 16) | (g << 8) | b);
}
