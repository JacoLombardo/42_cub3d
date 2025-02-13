/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/13 17:28:56 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include "struct.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

/* WIDTH and HEIGHT: screen resolution */
/* # define WIDTH 960
# define HEIGHT 720 */
# define WIDTH 1280
# define HEIGHT 720
/* # define WIDTH 1920
# define HEIGHT 1080 */
/* GRID: grid size (width and height) */
# define GRID 100
/* Field of View (FOV): The total horizontal viewing angle of the camera
	(in this case in radiants) */
# define FOV 1.5708
# define ESC 65307

/* Cleanup */
void		ft_free_tab(char **tab);
void		ft_free_config(t_config *config);
void		ft_free_data(t_data *data);
void		ft_parser_cleanup(t_config *config, char *line, int fd, char *type);
void		ft_libx_cleanup(t_data *data, t_config *config);

/* Events */
int			ft_event_close_win(t_data *data);
int			ft_events_keyboard(int keycode, t_data *data, t_player *player);

/* Init */
t_config	*ft_config_init(t_config *config);
void		ft_data_init(t_data *data, t_config *config);
void		ft_events_init(t_data *data);
void		ft_libx_init(t_data *data, t_config *config);

/* Libx */
void		ft_mlx_pixel_put(t_image *image, int x, int y, int color);

/* Map Check */
char		**ft_map_clone(t_config *map);
void		ft_map_check(char **map, t_config *config);

/* Parser */
t_config	*ft_parser(char *input, t_config *config);

/* Parser Utils */
int			ft_skip(char *line, int i);
void		ft_element_sort(t_config *map, char *copy, char element);
int			ft_strlen2(char *line, int i);
int			ft_filled(t_config *map);
int			ft_check_n_player(t_config *config, char **map, int len);

/* Screen */
void		ft_render_screen(t_data *data);
long long	ft_get_time(void);

/* Test */
void		ft_print_config(t_config *config);

/* Utils */
int			ft_tab_len(char **tab);

void		ft_create_img(t_config *config, t_data *data);

#endif
