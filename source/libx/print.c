/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/03/01 11:56:27 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_texture	*ft_get_face(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (data->texts[2]);
		else
			return (data->texts[3]);
	}
	else
	{
		if (ray->dir_y > 0)
			return (data->texts[0]);
		else
			return (data->texts[1]);
	}
}

void	ft_calc_pixel(t_seg *seg, t_texture *text, t_data *data)
{
	int	color;

	color = 0;
	if (seg->y < seg->wall_bot)
		ft_mlx_pixel_put(data, seg->y, seg->x, data->config->f);
	else if (seg->y > seg->wall_top)
		ft_mlx_pixel_put(data, seg->y, seg->x, data->config->c);
	else
	{
		text->y = (int)(((seg->y - seg->wall_bot) / (double)seg->wall_height)
				* text->height);
		color = *(int *)(text->addr + (text->y * text->line_length + text->x
					* (text->bpp / 8)));
		ft_mlx_pixel_put(data, seg->y, seg->x, color);
	}
}

void	ft_print_wall(t_ray *ray, t_data *data)
{
	int			pix_y;
	t_seg		seg;
	t_texture	*text;

	seg.wall_height = (WIDTH / (ray->perp_wall_dist)) * SCALING_FACTOR;
	seg.wall_top = (HEIGHT / 2) + (seg.wall_height / 2);
	seg.wall_bot = (HEIGHT / 2) - (seg.wall_height / 2) + 1;
	text = ft_get_face(ray, data);
	seg.x = ray->pixel;
	ft_calc_texture(ray, text, data);
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		seg.y = pix_y;
		ft_calc_pixel(&seg, text, data);
		pix_y++;
	}
}
