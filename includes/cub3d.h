/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 15:53:58 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
}			t_map;

typedef struct s_2D
{
	int		x;
	int		y;
	int		value;
}			t_2D;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		res_y;
	int		res_x;
	int		bbp; // = 4
}			t_data;

/* Parser */
int			ft_skip(char *line, int i);
int			ft_strlen2(char *line, int i);
void		ft_parser(char *input, t_map *map);

/* Screen */
int			init_screen(t_data *data);
void		render_screen(t_data *data);
void		init_data(t_data *data);

/* Events */
int			events_keyboard(int keycode, t_data *data);
void		init_events(t_data *data);
int			event_close_win(t_data *data);




#endif
