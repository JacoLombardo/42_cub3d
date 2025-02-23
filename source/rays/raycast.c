/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:30 by nboer             #+#    #+#             */
/*   Updated: 2025/02/23 15:40:18 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_distance2(t_intersect *p, t_player *player, double angle)
{
	double	dx;
	double	distance;

	dx = player->pos_x - p->x;
	distance = fabs(dx * cos(ft_dtor(angle)));
	return (distance);
}

/* void	ft_cast_ray2(t_ray *ray, t_data *data)
{
	double	deltaDistX;
	double	deltaDistY;
	 //which box of the map we're in
	int mapX;
	int mapY;
	//length of ray from current position to next x or y-side
	double sideDistX;
	double sideDistY;

	ray->pos = (2 * ray->pixel / WIDTH) - 1.0;
	ray->dir_x = data->player->dir_x + data->plane->x * ray->pos;
	ray->dir_y = data->player->dir_y + data->plane->y * ray->pos;
	deltaDistX = fabs(1 / ray->dir_x);
	deltaDistY = fabs(1 / ray->dir_y);
	 //which box of the map we're in
	mapX = data->player->dir_x / GRID;
	mapY = data->player->dir_y / GRID;

	//length of ray from one x or y-side to next x or y-side
	deltaDistX = (ray->dir_x == 0) ? 1e30 : fabs(1 / ray->dir_x);
	deltaDistY = (ray->dir_y == 0) ? 1e30 : fabs(1 / ray->dir_y);
	double perpWallDist;

	 //what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;

	int hit = 0; //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	 //calculate step and initial sideDist
	 if (ray->dir_x < 0)
	 {
	   stepX = -1;
	   sideDistX = (data->player->dir_x / GRID - mapX) * deltaDistX;
	 }
	 else
	 {
	   stepX = 1;
	   sideDistX = (mapX + 1.0 - data->player->dir_x / GRID) * deltaDistX;
	 }
	 if (ray->dir_y < 0)
	 {
	   stepY = -1;
	   sideDistY = (data->player->dir_y / GRID - mapY) * deltaDistY;
	 }
	 else
	 {
	   stepY = 1;
	   sideDistY = (mapY + 1.0 - data->player->dir_y / GRID) * deltaDistY;
	 }
	 while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (data->config->map[mapX][mapY] > 0) hit = 1;
      }
	  //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);
	  printf("wall hit at x: %i, y: %i\n", mapX, mapY);
} */

void ft_cast_ray2(t_ray *ray, t_data *data)
{
    double deltaDistX, deltaDistY;
    int mapX, mapY;
    double sideDistX, sideDistY;
    double perpWallDist;
    int stepX, stepY;
    int hit = 0;
    int side;

    ray->pos = (2 * ray->pixel / WIDTH) - 1.0;
    ray->dir_x = data->player->dir_x + data->plane->x * ray->pos;
    ray->dir_y = data->player->dir_y + data->plane->y * ray->pos;

    deltaDistX = (ray->dir_x == 0) ? 1e30 : fabs(GRID / ray->dir_x);
    deltaDistY = (ray->dir_y == 0) ? 1e30 : fabs(GRID / ray->dir_y);

    mapX = (int)(data->player->pos_x / GRID);
    mapY = (int)(data->player->pos_y / GRID);

    if (ray->dir_x < 0)
    {
        stepX = -1;
        sideDistX = ((data->player->pos_x - (mapX * GRID)) / GRID) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (((mapX + 1) * GRID - data->player->pos_x) / GRID) * deltaDistX;
    }

    if (ray->dir_y < 0)
    {
        stepY = -1;
        sideDistY = ((data->player->pos_y - (mapY * GRID)) / GRID) * deltaDistY;
    }
    else
    {
        stepY = 1;
        sideDistY = (((mapY + 1) * GRID - data->player->pos_y) / GRID) * deltaDistY;
    }

    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }

        if (data->config->map[mapX][mapY] > 0)
            hit = 1;
    }

    if (side == 0)
        perpWallDist = (sideDistX - deltaDistX) * GRID;
    else
        perpWallDist = (sideDistY - deltaDistY) * GRID;

    printf("Wall hit at x: %d, y: %d\n", mapX, mapY);
}

// void	ft_cast_ray(t_ray *ray, t_data *data)
// {
// 	ray->pos = (2 * ray->pixel / WIDTH) - 1.0;
// 	ray->dir_x = data->player->dir_x + data->plane->x * ray->pos;
// 	ray->dir_y = data->player->dir_y + data->plane->y * ray->pos;
// 	printf("RAY angle: %f, dir_x: %f, dir_y: %f\n", ray->angle, ray->dir_x, ray->dir_y);
// 	ray->dis = 0;
// 	ray->hori_int = NULL;
// 	ray->vert_int = NULL;
// 	printf("\nHORIZONTAL\n");
// 	ft_hori_intersection(ray, data);
// 	printf("\nVERTICAL\n");
// 	ft_vert_intersection(ray, data);
// 	//printf("\n");
// 	if (!ray->vert_int || ray->vert_int->oor || ft_distance2(ray->hori_int, data->player, ray->angle) 
// 			< ft_distance2(ray->vert_int, data->player, ray->angle))
// 	{
// 		printf("Printing wall for horizontal intersection\n\n");
// 		ray->hori_int->dis = ft_distance2(ray->hori_int, data->player, ray->angle);
// 		ft_print_wall('h', ray->hori_int, ray, data);
// 	}
// 	else if (ray->hori_int->oor || ft_distance2(ray->hori_int, data->player, ray->angle) > ft_distance2(ray->vert_int, data->player, ray->angle))
// 	{
// 		printf("Printing wall for vertical intersection\n\n");
// 		ray->vert_int->dis = ft_distance2(ray->vert_int, data->player, ray->angle);
// 		ft_print_wall('v',ray->vert_int, ray, data);
// 	}
// }

void castRay(t_ray *ray, t_data *data)
{
    double rayDirX = cos(ray->angle);
    double rayDirY = sin(ray->angle);

    double deltaDistX = fabs(1 / rayDirX);
    double deltaDistY = fabs(1 / rayDirY);

    int mapX = (int)(data->player->pos_x / GRID);
    int mapY = (int)(data->player->pos_y / GRID);

    double sideDistX, sideDistY;

    if (rayDirX < 0) {
        sideDistX = (data->player->pos_x - mapX * GRID) * deltaDistX / GRID;
    } else {
        sideDistX = ((mapX + 1) * GRID - data->player->pos_x) * deltaDistX / GRID;
    }

    if (rayDirY < 0) {
        sideDistY = (data->player->pos_y - mapY * GRID) * deltaDistY / GRID;
    } else {
        sideDistY = ((mapY + 1) * GRID - data->player->pos_y) * deltaDistY / GRID;
    }

    int stepX, stepY;
    int hit = 0;
    int side;

    if (rayDirX < 0) {
        stepX = -1;
    } else {
        stepX = 1;
    }

    if (rayDirY < 0) {
        stepY = -1;
    } else {
        stepY = 1;
    }

    while (!hit) {
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }

        if (data->config->map[mapY][mapX] == '1') {
            hit = 1;
        }
    }

    float perpWallDist;
    if (side == 0) {
        perpWallDist = (mapX - data->player->pos_x / GRID + (1 - stepX) / 2) / rayDirX;
    } else {
        perpWallDist = (mapY - data->player->pos_y / GRID + (1 - stepY) / 2) / rayDirY;
    }
	// printf("wall hit at x: %i, y: %i and perpwall: %f\n", mapX, mapY, perpWallDist);
	ft_print_wall2(side, ray->pixel, perpWallDist * GRID, data);
}

void	ft_init_rays(t_data *data)
{
	int		i;
	double	start_angle;
	t_ray	**rays;
	t_ray	*ray;

	i = 0;
	start_angle = data->player->view_angle - (FOV / 2); //radians or degrees?
	rays = (t_ray **)malloc(WIDTH * sizeof(t_ray *));
	if (!rays)
		ft_game_cleanup(data, "malloc");
	data->rays = rays;
	while (i < WIDTH)
	{
		ray = (t_ray *)malloc(1 * sizeof(t_ray));
		if (!ray)
			ft_game_cleanup(data, "malloc");
		ray->pixel = i + 1;
		//ray->angle = start_angle + (data->ray_angle * i);
		//rays[i] = ray;
		// printf("%i-", i);
		//ft_cast_ray(rays[i], data);

		ray->angle = atan2(data->player->dir_y, data->player->dir_x) + (i / (double)WIDTH - 0.5f) * FOV;
		//ray->angle = start_angle + (data->ray_angle * i);
		rays[i] = ray;
        castRay(ray, data);
        //int lineHeight = (int)(WALL_HEIGHT / distance * WIDTH);
		//(void)lineHeight;
		i++;
	}
	printf("FINISHED\n");
	// ft_free_rays(rays);
	//data->rays = NULL;
}
