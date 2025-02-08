/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 12:35:16 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libraries/libft/libft.h"
# include "libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_map
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	struct s_2D	**map;
}				t_map;

typedef struct s_2D
{
	int			x;
	int			y;
	int			value;
}				t_2D;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

/* Parser */
int				ft_skip(char *line, int i);
int				ft_strlen2(char *line, int i);
t_map			*ft_parser(char *map);

/* Screen */


/* Error */
int				put_str_error(char* s, int exit_code);

#endif
