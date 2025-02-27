/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:23:17 by nboer             #+#    #+#             */
/*   Updated: 2025/02/27 10:31:47 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_get_texture(int i, t_data *data)
{
	if (i == 0)
		return (data->config->no);
	else if (i == 1)
		return (data->config->so);
	else if (i == 2)
		return (data->config->we);
	else if (i == 3)
		return (data->config->ea);
	else
		return (NULL);
}

/* void	ft_calc_texture(t_ray *ray, t_texture *tex, t_data *data)
{
	double	wall_x;

	(void)data;
	if (ray->side == 0)
		wall_x = data->player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = data->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex->x = (int)(wall_x * (double)(tex->width));
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
    	tex->x = tex->width - tex->x - 1;
} */

void	ft_calc_texture(t_ray *ray, t_texture *tex, t_data *data)
{
	double	wall_x;

	(void)data;
	if (ray->side == 0) // if vertical wall-> use y-coordinate of ray collision
		wall_x = ray->hit_y; // wallX represents the exact point where the ray hit the wall
	else // if horizontal wall-> use x-coordinate of collision
		wall_x = ray->hit_x;
	wall_x -= floor(wall_x); //tells where exactly in the cell you hit the wall, because your remove the round numbers (for example 2,73 is now 0,73 which tells you what part of the texture to draw)
	tex->x = (int)(wall_x * (double)(tex->width)); //translate to the domain of the texture
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
		tex->x = tex->width - tex->x - 1; // flip the texture horizontally if the ray hits from the right or from the bottom
}

void	ft_textures_init(t_data *data)
{
	int			i;
	t_texture	*text;

	i = 0;
	while (i < 4)
		data->texts[i++] = NULL;
	i = 0;
	while (i < 4)
	{
		text = (t_texture *)malloc(1 * sizeof(t_texture));
		if (!text)
			ft_init_cleanup(data, NULL, "malloc");
		data->texts[i] = text;
		text->img = mlx_xpm_file_to_image(data->mlx, ft_get_texture(i, data),
				&text->width, &text->height);
		if (!text->img)
			ft_init_cleanup(data, NULL, "texture");
		text->addr = mlx_get_data_addr(text->img, &text->bpp,
				&text->line_length, &text->endian);
		if (!text->addr)
			ft_init_cleanup(data, NULL, "texture");
		i++;
	}
}
