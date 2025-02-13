/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 15:51:06 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 960
# define HEIGHT 720
/* # define WIDTH 1920
# define HEIGHT 1080 */
# define BBP 4
# define STD_COLOR 0xFFFFFF
# define BLUE 0x0000FF
# define RED 0xFF0000
# define COS 0.707105
# define SIN 0.707108
# define ESC 65307
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
}				t_data;

/* Cleanup */
void			ft_free_tab(char **tab);
void			ft_free_config(t_config *config);
void			ft_parser_cleanup(t_config *config, char *line, int fd,
					char *type);

/* Events */
int				ft_event_close_win(t_data *data);
int				ft_events_keyboard(int keycode, t_data *data);

/* Init */
t_config		*ft_config_init(t_config *config);
void			ft_data_init(t_data *data);
void			ft_events_init(t_data *data);
int				ft_libx_init(t_data *data);

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
int				init_screen(t_data *data);
void			render_screen(t_data *data);
void			init_data(t_data *data);

/* Events */
int				ft_events_keyboard(int keycode, t_data *data);
int				ft_event_close_win(t_data *data);

/* Test */
void			ft_print_config(t_config *config);

/* Utils */
int				ft_tab_len(char **tab);

void	ft_create_img(t_config *config, t_data *data);
void	ft_mlx_pixel_put(t_image *data, int x, int y, int color);
char	**transpose_map(char **map);

#endif
