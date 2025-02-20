/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:29:33 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/20 17:40:04 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_plane
{
	int		x;
	int		y;
	double	size;
}				t_plane;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	char		orientation;
}				t_player;

typedef struct s_ray
{
	int			x;
	int			y;
	int			pixel;
	double		angle;
	double		dir_x;
	double		dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	double		perp_wall_dist;
}				t_ray;

typedef struct s_config
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	int			map_height;
	t_player	*player;
}				t_config;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	char		*buff;
}				t_image;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			width;
	int			height;
	int			endian;
}				t_texture;

typedef struct s_data
{
	int			keys[256];
	void		*mlx;
	void		*win;
	t_image		*image;
	double		ray_angle;
	t_config	*config;
	t_texture	*texture;
	t_player	*player;
	t_plane		*plane;
	t_ray		**rays;
}				t_data;

#endif
