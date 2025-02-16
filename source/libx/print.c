/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:52 by nboer             #+#    #+#             */
/*   Updated: 2025/02/15 15:00:47 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int get_wall_height(float ray_distance)
{
	if (ray_distance <= 0.1)
		ray_distance = 0.1;
	return ((int) HEIGHT / ray_distance);
}


