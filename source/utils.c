/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:07:06 by jalombar          #+#    #+#             */
/*   Updated: 2025/02/20 14:34:02 by nboer            ###   ########.fr       */
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

double	ft_distance(int p1_x, int p1_y, int p2_x, int p2_y)
{
	double	dx;
	double	dy;
	double	distance;

	dx = p1_x - p2_x;
	dy = p1_y - p2_y;
	distance = sqrt(dx * dx + dy * dy);
	return (distance);
}

void print_image_info(t_image *image)
{
    if (image == NULL)
    {
        printf("Image is NULL.\n");
        return;
    }
    printf("Image Information:\n");
    printf("  img: %p\n", image->img);
    printf("  addr: %p\n", image->addr);
    printf("  bpp: %d\n", image->bpp);
    printf("  line_length: %d\n", image->line_length);
    printf("  endian: %d\n", image->endian);
    printf("  buff: %p\n", image->buff);
}

