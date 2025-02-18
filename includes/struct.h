/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:29:33 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/18 15:42:23 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_2D
{
	int		x;
	int		y;
}				t_2D;

typedef struct s_intersect
{
	double	x;
	double	y;
	double	xa;
	double	ya;
	double	dis_x;
	double	dis_y;
}				t_intersect;

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
	int			view_angle;
	double		dir_x;
	double		dir_y;
	char		orientation;
}				t_player;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		pos;
	double		xa;
	double		ya;
	double		dis;
	double		angle;
	t_intersect	*hori_int;
	t_intersect	*vert_int;
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
	t_player	*player;
}				t_config;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bbp;
	int			line_length;
	int			endian;
	char		*buff;
}				t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		*image;
	double		ray_angle;
	t_config	*config;
	t_player	*player;
	t_plane		*plane;
	t_ray		**rays;
}				t_data;

#endif
