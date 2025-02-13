/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:29:33 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/13 17:23:34 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	double		dir_x;
	double		dir_y;
	char		orientation;
}				t_player;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		dis;
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
}				t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		*image;
	double		ray_angle;
}				t_data;

#endif