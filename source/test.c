/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:48:32 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 13:49:16 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("NO: %s\n", map->no);
	ft_printf("SO: %s\n", map->so);
	ft_printf("WE: %s\n", map->we);
	ft_printf("EA: %s\n", map->ea);
	ft_printf("Ceiling: %s\n", map->c);
	ft_printf("Floor: %s\n", map->f);
	ft_printf("\nMAP: \n\n");
	while (map->map[i])
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}
