/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:29:33 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/25 13:56:02 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_seg
{
	int			x;
	int			y;
	int			wall_height;
	int			wall_top;
	int			wall_bot;
}				t_seg;

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
	double		hit_x;
	double		hit_y;
}				t_ray;

typedef struct s_config
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f;
	int			c;
	char		**map;
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
	int			x;
	int			y;
}				t_texture;

typedef struct s_data
{
	int			keys[6];
	void		*mlx;
	void		*win;
	t_image		*image;
	double		ray_angle;
	t_config	*config;
	t_texture	*tex;
	t_texture	*texs[4];
	t_player	*player;
	t_plane		*plane;
	t_ray		**rays;
}				t_data;

#endif
