/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:23:17 by nboer             #+#    #+#             */
/*   Updated: 2025/02/20 12:26:53 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_textures_init(t_data *data)
{
	t_texture	*tex;

	tex = (t_texture *)malloc(1 * sizeof(t_texture));
	if (!tex)
	{
		ft_game_cleanup(&data, "texture"); //<- needs update
		return; 
	}
	tex->img = mlx_xpm_file_to_image(data->mlx, "includes/assets/wall.xpm",
			&(tex->width), &(tex->height));
	tex->addr = mlx_get_data_addr(tex->img, tex->bpp, tex->line_length,
			tex->endian);
	data->texture = tex;
}

void setup_textures()
{
	
}
