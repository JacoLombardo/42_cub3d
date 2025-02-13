/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:57:43 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/13 14:16:07 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* t_line	*ft_to_line(t_line *line, t_matrix *p1, t_matrix *p2)
{
	line->x1 = p1->iso->x;
	line->y1 = p1->iso->y;
	line->color1 = p1->color;
	line->x2 = p2->iso->x;
	line->y2 = p2->iso->y;
	line->color2 = p2->color;
	line->dx = abs(p2->iso->x - p1->iso->x);
	line->dy = abs(p2->iso->y - p1->iso->y);
	if (p1->iso->x < p2->iso->x)
		line->sx = 1;
	else
		line->sx = -1;
	if (p1->iso->y < p2->iso->y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
	return (line);
}

void	ft_draw_line(t_line *line, t_image *image)
{
	int	e2;

	while (1)
	{
		ft_mlx_pixel_put(image, line->x1, line->y1, line->color1);
		if (line->x1 == line->x2 && line->y1 == line->y2)
			break ;
		e2 = 2 * line->err;
		if (e2 > -line->dy)
		{
			line->err -= line->dy;
			line->x1 += line->sx;
		}
		if (e2 < line->dx)
		{
			line->err += line->dx;
			line->y1 += line->sy;
		}
	}
}

void	ft_print_line(t_matrix *p1, t_matrix *p2, t_image *image)
{
	t_line	*line;

	line = (t_line *)malloc(1 * sizeof(t_line));
	if (!line)
		return ;
	line = ft_to_line(line, p1, p2);
	ft_draw_line(line, image);
	free(line);
} */

/* void	ft_fill(char **map, t_image *image)
{
	int	x;
	int	y;

	x = 0;
	while (x < size->x)
	{
		y = 0;
		while (y < size->y)
		{
			if (x > 0)
				ft_print_line(matrix[x - 1][y], matrix[x][y], image);
			if (y > 0)
				ft_print_line(matrix[x][y - 1], matrix[x][y], image);
			y++;
		}
		x++;
	}
} */

void	ft_create_img(t_config *config, t_data *data)
{
	int			x;
	int			y;

	x = 0;
	while (x < ft_tab_len(config->map))
	{
		y = 0;
		while (y < (int)ft_strlen(config->map[x]))
		{
			if (config->map[x][y] == '1')
				ft_mlx_pixel_put(data->image, x * 10, y * 10, 16777215);
			y++;
		}
		x++;
	}
}
