/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:02:43 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/19 11:57:02 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bbp / 8));
	*(unsigned int *)dst = color;
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

