/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:07:18 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/20 13:38:48 by jalombar         ###   ########.fr       */
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

	if (degrees == 90 || degrees == 270)
		return (1);
	radiants = degrees * (M_PI / 180.0);
	tan_nb = tan(radiants);
	return (tan_nb);
}
