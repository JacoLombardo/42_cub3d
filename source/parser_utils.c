/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:48:51 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/08 12:36:29 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_skip(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

int	ft_strlen2(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i] && line[i] != '\n' && line[i] != ' ')
	{
		i++;
		len++;
	}
	return (len);
}
