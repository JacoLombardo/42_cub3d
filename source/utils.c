/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:07:06 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/15 12:16:21 by jalombar         ###   ########.fr       */
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

int	ft_farer(t_2D *p1, t_2D *p2)
{
	int	d1;
	int	d2;

	d1 = (p1->xa * p1->xa) + (p1->ya * p1->ya);
	d2 = (p2->xa * p2->xa) + (p2->ya * p2->ya);
	if (d1 > d2)
		return (1);
	else
		return (0);
}
