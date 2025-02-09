/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:48:32 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/09 11:13:06 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_config(t_config *config)
{
	int	i;

	i = 0;
	ft_printf("NO: %s\n", config->no);
	ft_printf("SO: %s\n", config->so);
	ft_printf("WE: %s\n", config->we);
	ft_printf("EA: %s\n", config->ea);
	ft_printf("Ceiling: %s\n", config->c);
	ft_printf("Floor: %s\n", config->f);
	ft_printf("\nMAP: \n\n");
	while (config->map[i])
	{
		ft_printf("%s\n", config->map[i]);
		i++;
	}
}
