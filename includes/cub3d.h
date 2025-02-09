/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 11:29:18 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
}			t_config;

/* Cleanup */
void		ft_free_tab(char **tab);
void		ft_free_config(t_config *config);
void		ft_parser_cleanup(t_config *config, char *line, int fd);

/* Init */
t_config	*ft_config_init(t_config *config);

/* Map Check */
char		**ft_map_clone(t_config *map);
void		ft_map_check(char **map, t_config *config);

/* Parser */
t_config	*ft_parser(char *input, t_config *config);

/* Parser Utils */
int			ft_skip(char *line, int i);
int			ft_tab_len(char **tab);
void		ft_element_sort(t_config *map, char *copy, char element);
int			ft_strlen2(char *line, int i);
int			ft_filled(t_config *map);

/* Test */
void		ft_print_config(t_config *config);

#endif
