/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 15:51:06 by nboer            ###   ########.fr       */
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
#include <sys/time.h>
#include <sys/wait.h>

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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		res_y;
	int		res_x;
	int		bbp; // = 4
}			t_data;

/* Cleanup */
void			ft_free_tab(char **tab);
void			ft_free_config(t_config *config);
void			ft_parser_cleanup(t_config *config, char *line, int fd,
					char *type);

/* Init */
t_config		*ft_config_init(t_config *config);

/* Map Check */
char			**ft_map_clone(t_config *map);
void			ft_map_check(char **map, t_config *config);

/* Parser */
t_config		*ft_parser(char *input, t_config *config);

/* Parser Utils */
int				ft_skip(char *line, int i);
void			ft_element_sort(t_config *map, char *copy, char element);
int				ft_strlen2(char *line, int i);
int				ft_filled(t_config *map);
int				ft_check_for_player(t_config *config, char **map, int len);

/* Screen */
int			init_screen(t_data *data);
void		render_screen(t_data *data);
void		init_data(t_data *data);

/* Events */
int			events_keyboard(int keycode, t_data *data);
void		init_events(t_data *data);
int			event_close_win(t_data *data);

/* Test */
void			ft_print_config(t_config *config);

/* Utils */
int				ft_tab_len(char **tab);

#endif
