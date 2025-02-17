/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:07:06 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/18 16:15:25 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

double	ft_distance(t_intersect *p, t_data *data)
{
	double	dx;
	double	dy;
	double	distance;

	dx = p->x - data->player->pos_x;
	dy = p->y - data->player->pos_y;
	distance = sqrt(dx * dx + dy * dy);
	return (distance);
}

int	ft_closer(t_intersect *p1, t_intersect *p2, t_data *data)
{
	double	d1;
	double	d2;

	d1 = 0;
	d2 = 0;
	d1 = sqrt(pow(data->player->pos_x - p1->x, 2) + pow(data->player->pos_y
				- p1->y, 2));
	d1 = sqrt(pow(data->player->pos_x - p2->x, 2) + pow(data->player->pos_y
				- p2->y, 2));
	if (d1 < d2)
		return (1);
	else
		return (0);
}
