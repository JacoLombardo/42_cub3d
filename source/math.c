/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:07:18 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/14 15:13:36 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_dtor converts degrees to radiants */
double	ft_dtor(double degrees)
{
	double	radiants;

	radiants = degrees * (M_PI / 180.0);
	return (radiants);
}

/* ft_get_tan converts degrees to radiants and
	return the value of the tangent of the angle*/
double	ft_get_tan(double degrees)
{
	double	radiants;
	double	tan_nb;

	radiants = degrees * (M_PI / 180.0);
	tan_nb = tan(radiants);
	return (tan_nb);
}

/* ft_calc_xa calculate the distance from the starting point
	of the ray to the first horizontal intersection */
double	ft_calc_xa(t_ray *ray)
{
	int		direction;
	double	xa;

	if (ray->dir_x < 0)
		direction = -1;
	else
		direction = 1;
	xa = ((GRID / 2) / ft_get_tan(ray->angle)) * direction;
	return (xa);
}

/* ft_calc_ya calculate the distance from the starting point
	of the ray to the first vertical intersection */
double	ft_calc_ya(t_ray *ray)
{
	int		direction;
	double	ya;

	if (ray->dir_y < 0)
		direction = -1;
	else
		direction = 1;
	ya = ((GRID / 2) * ft_get_tan(ray->angle)) * direction;
	return (ya);
}
