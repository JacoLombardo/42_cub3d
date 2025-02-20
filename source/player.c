/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:29:47 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/20 13:36:21 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_player_dir(char orientation, t_player *player)
{
	player->orientation = orientation;
	if (player->orientation == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (player->orientation == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (player->orientation == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (player->orientation == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}
