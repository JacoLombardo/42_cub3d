/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:23:17 by nboer             #+#    #+#             */
/*   Updated: 2025/02/23 17:15:36 by nboer            ###   ########.fr       */
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
