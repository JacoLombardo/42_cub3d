/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:02:43 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/20 14:36:39 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

char	ft_move_orientation(char direction, t_player *player)
{
	if (player->orientation == 'N' && direction == 'l')
		return ('W');
	else if (player->orientation == 'N' && direction == 'r')
		return ('E');
	else if (player->orientation == 'W' && direction == 'l')
		return ('S');
	else if (player->orientation == 'W' && direction == 'r')
		return ('N');
	else if (player->orientation == 'S' && direction == 'l')
		return ('E');
	else if (player->orientation == 'S' && direction == 'r')
		return ('W');
	else if (player->orientation == 'E' && direction == 'l')
		return ('N');
	else if (player->orientation == 'E' && direction == 'r')
		return ('S');
}

void	ft_update_image(t_data *data)
{
	ft_init_rays(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
}

// void	init_textures()
// {
// 	mlx_texture_t *texture;
	
// 	mlx_load_png("./temp/sus.png");
// 	if (!texture)
// 		error();

// 	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// 	if (!img)
// 		error();
// }	

