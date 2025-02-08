/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:05:56 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 15:26:57 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

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

/* Cleanup */
void		ft_free_map(t_map *map);
void		ft_parser_cleanup(t_map *map, char *line, int fd);

/* Init */
t_map		*ft_map_init(t_map *map);

/* Parser */
int			ft_skip(char *line, int i);
void		ft_element_sort(t_map *map, char *copy, char element);
int			ft_strlen2(char *line, int i);
int			ft_filled(t_map *map);
void		ft_parser(char *input, t_map *map);

/* Test */
void		ft_print_map(t_map *map);

#endif
