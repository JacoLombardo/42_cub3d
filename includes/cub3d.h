/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/27 21:10:58 by nboer            ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 600
# define GRID 64
# define STEP 1
# define WALL_HEIGHT 1.0
# define FOV 1.0471975512
# define SCALING_FACTOR 0.6

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define LIGHTBLUE 0xADD8E6

/* Cleanup */
void		ft_parser_cleanup(t_config *config, char *line, int fd, char *type);
void		ft_init_cleanup(t_data *data, t_config *config, char *type);
void		ft_game_cleanup(t_data *data, char *type);

/* Cleanup Utils */
void		ft_free_tab(char **tab);
void		ft_free_config(t_config *config);
void		ft_free_rays(t_ray **rays);
void		ft_free_textures(t_texture **texts, t_data *data);
void		ft_free_data(t_data *data);

/* Movements */
int			ft_move_player_ws(char direction, t_data *data);
int			ft_move_player_ad(char direction, t_data *data);
int			ft_rotate_player(t_player *player, double angle_increment);

/* Events */
int			ft_key_release(int keycode, t_data *data);
int			ft_key_press(int keycode, t_data *data);
int			ft_event_close_win(t_data *data);
int			ft_events_keyboard(t_data *data);

/* Libx */
void		ft_mlx_pixel_put(t_data *data, int posY, int posX, int color);
long long	ft_get_time(void);
void		ft_update_image(t_data *data);

/* Print */
t_texture	*ft_get_face(t_ray *ray, t_data *data);
void		ft_calc_pixel(t_seg *seg, t_texture *tex, t_data *data);
void		ft_print_wall(t_ray *ray, t_data *data);
int			ft_darken_color(int color, double factor);

/* Textures */
char		*ft_get_texture(int i, t_data *data);
void		ft_calc_texture(t_ray *ray, t_texture *tex, t_data *data);
void		ft_textures_init(t_data *data);

/* Map Check */
int			ft_format_color(char *str, t_config *config);
char		**ft_map_clone(t_config *config);
void		ft_map_check(char **map, t_config *config);

/* Parser */
t_config	*ft_parser(char *input, t_config *config);

/* Parser Utils */
int			ft_skip(char *line, int i);
void		ft_element_sort(t_config *config, char *copy, char element);
int			ft_strlen2(char *line, int i);
int			ft_filled(t_config *config);
int			ft_check_n_player(t_config *config, char **map, int len);

/* Init */
void		ft_config_init(t_config *config);
void		ft_data_init(t_data *data, t_config *config);
void		ft_events_init(t_data *data);
void		ft_libx_init(t_data *data);

/* Math */
double		ft_dtor(double degrees);
double		ft_get_tan(double degrees);
void		normalize_vector(t_ray *ray);

/* Player */
void		ft_set_player_dir(char orientation, t_player *player);

/* Raycast */
void		ft_cast_ray(t_ray *ray, t_data *data);
void		ft_init_rays(t_data *data);

/* Raycast Utils */
void		ft_calc_perp_wall(t_ray *ray, t_data *data);

/* Test */
void		ft_print_config(t_config *config);

/* Utils */
int			ft_tab_len(char **tab);
int			ft_inside_map(int x, int y, char **map);
void		print_image_info(t_image *image);

#endif
