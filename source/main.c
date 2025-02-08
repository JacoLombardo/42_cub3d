/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:10:26 by nboer             #+#    #+#             */
/*   Updated: 2025/02/08 11:47:02 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	//check if input = .cub file?
	if (argc == 2)
	{	
		init(&structname);
		events_init(&structname);
		render_screen(&structname);
		mlx_loop(structname.mlx_ptr);
		mlx_clean(&structrname);
		exit(EXIT_SUCCESS);
	}
	//input error;
}
