/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:37:50 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 19:41:04 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	protection(t_info *map)
{
	if (map->angle >= 2 * M_PI)
		map->angle -= 2 * M_PI;
	else if (map->angle < 0)
		map->angle += 2 * M_PI;
}

void	problem(t_info *map, double *target_x, double *target_y)
{
	int	map_x;
	int	map_y;

	map_x = ((map->player_x + ((*target_x) * 2)) / TILE_SIZE);
	map_y = ((map->player_y + ((*target_y) * 2)) / TILE_SIZE);
	if (map_x > 0 && map_x < get_width() && map_y > 0 && map_y < get_height()
		&& map->map[map_y][map_x] == '0')
	{
		map->player_x += *target_x;
		map->player_y += *target_y;
	}
}

void	loop_ray(t_info *map)
{
	t_cord	h;
	t_cord	v;
	double	k ;
	double	disrays;

	k = 0;
	disrays = deg2rad(FOV) / map->width;
	map->angle_fov = map->angle - deg2rad(FOV / 2);
	while (k < map->width)
	{
		if (map->angle_fov > 2 * M_PI)
			map->angle_fov -= 2 * M_PI;
		if (map->angle_fov < 0)
			map->angle_fov += 2 * M_PI;
		h = horizontal_intersection(map, map->angle_fov);
		h.is_vertical = false;
		v = vertical_intersection(map, map->angle_fov);
		v.is_vertical = true;
		map->inter = smallest(map, h, v);
		map->dis *= cos(map->angle - map->angle_fov);
		drawalls(map, k);
		map->angle_fov += disrays;
		k++;
	}
}

int	get_height(void)
{
	int	i;

	i = 0;
	while (g_info_path->info->map[i])
		i++;
	return (i);
}

int	get_width(void)
{
	int	i;
	int	j;
	int	max_width;

	i = 0;
	j = 0;
	max_width = 0;
	while (g_info_path->info->map[i])
	{
		j = 0;
		while (g_info_path->info->map[i][j])
			j++;
		if (j > max_width)
			max_width = j;
		i++;
	}
	return (max_width);
}
