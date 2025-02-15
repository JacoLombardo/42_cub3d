/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/15 16:53:36 by nboer            ###   ########.fr       */
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
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

/* # define WIDTH 960
# define HEIGHT 720 */
# define WIDTH 1280
# define HEIGHT 720
/* # define WIDTH 1920
# define HEIGHT 1080 */
# define GRID 10
# define FOV 60
//# define FOV 90
# define M_PI 3.14159265358979323846
# define ESC 65307

# define RED 0xFF0000
# define BLUE 0x00FF00
# define GREEN 0x0000FF

/* Cleanup */
void		ft_parser_cleanup(t_config *config, char *line, int fd, char *type);
void		ft_init_cleanup(t_data *data, t_config *config, char *type);

/* Cleanup Utils */
void		ft_free_tab(char **tab);
void		ft_free_config(t_config *config);
void		ft_free_data(t_data *data);
void		ft_free_rays(t_ray **rays);

/* Draw */
void		ft_create_img(t_config *config, t_data *data);

/* Events */
int			ft_event_close_win(t_data *data);
int			ft_events_keyboard(int keycode, t_data *data, t_player *player);

/* Libx */
void		ft_mlx_pixel_put(t_image *image, int x, int y, int color);

/* Screen */
void		ft_render_screen(t_data *data);
long long	ft_get_time(void);
void		my_pixel_put(t_data *data, int posY, int posX, int color);

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


/* Intersections */
int			ft_check_wall(t_2D *intersection, t_data *data);
t_2D		*ft_hori_coordinates(t_ray *ray, t_data *data, int first);
t_2D		*ft_vert_coordinates(t_ray *ray, t_data *data, int first);
void		ft_hori_intersection(t_ray *ray, t_data *data);
void		ft_vert_intersection(t_ray *ray, t_data *data);

/* Raycast */
void		ft_cast_ray(t_ray *ray, t_data *data);
void		ft_init_rays(t_data *data);


/* Init */
void		ft_config_init(t_config *config);
void		ft_data_init(t_data *data, t_config *config);
void		ft_events_init(t_data *data);
void		ft_libx_init(t_data *data);

/* Math */
double		ft_dtor(double degrees);
double		ft_get_tan(double degrees);
double		ft_calc_xa(t_ray *ray);
double		ft_calc_ya(t_ray *ray);

/* Test */
void		ft_print_config(t_config *config);

/* Utils */
int			ft_tab_len(char **tab);
int			ft_farer(t_2D *p1, t_2D *p2);



#endif
