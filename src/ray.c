/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/06/04 17:51:32 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	_short(t_info *map, double x_percent, mlx_texture_t	*tex)
{
	uint8_t			*pixelx;
	uint8_t			*pixeli;

	map->x_tex = x_percent * tex->width;
	map->y_start = map->y_wall1;
	map->y_end = map->y_wall1 + map->y_wall2;
	if (map->y_end > map->height) 
		map->y_end = map->height;
	map->x_map = map->x_wall1;
	map->y_map = map->y_start * (map->y_start > 0);
	map->k = (double)tex->height / map->y_wall2;
	while (map->y_map < map->y_end)
	{
		map->y_tex = map->k * (map->y_map - map->y_start);
		pixelx = &tex->pixels[(((int)map->y_tex * tex->width) + \
			(int)map->x_tex) * tex->bytes_per_pixel];
		pixeli = &map->img->pixels[(((int)map->y_map * map->img->width) + \
			(int)map->x_map) * tex->bytes_per_pixel];
		ft_memmove(pixeli, pixelx, tex->bytes_per_pixel);
		map->y_map++;
	}
}

void	check_dir(t_info *map, int i, int j)
{
	if (map->map[i][j] == 'W')
		map->angle = M_PI;
	if (map->map[i][j] == 'E')
		map->angle = 0;
	if (map->map[i][j] == 'S')
		map->angle = M_PI / 2;
	if (map->map[i][j] == 'N')
		map->angle = 3 * M_PI / 2;
}

bool	has_wall(t_info *mlx, int x, int y)
{
	x /= TILE_SIZE;
	y /= TILE_SIZE;
	if (x < 0 || x >= mlx->rows || y < 0 || y >= mlx->cols)
		return (true);
	if (mlx->map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

t_cord	horizontal_intersection(t_info *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;

	mlx->is_ray_facing_up = ray_angle > M_PI;
	sign = 1;
	if (mlx->is_ray_facing_up)
		sign = -1;
	cord.ystep = (int)(mlx->player_y / TILE_SIZE) * TILE_SIZE;
	if (!mlx->is_ray_facing_up)
		cord.ystep += TILE_SIZE;
	cord.xstep = mlx->player_x + (cord.ystep - mlx->player_y) / tan(ray_angle);
	mlx->dx = sign * TILE_SIZE / tan(ray_angle);
	mlx->dy = sign * TILE_SIZE;
	while (true)
	{
		if ((mlx->is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep - TILE_SIZE)) || \
			(!mlx->is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += mlx->dx;
		cord.ystep += mlx->dy;
	}
	return (cord);
}

t_cord	vertical_intersection(t_info *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;

	mlx->is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	cord.xstep = (int)(1 + mlx->player_x / TILE_SIZE) * TILE_SIZE;
	if (mlx->is_ray_facing_left)
	{
		cord.xstep -= TILE_SIZE;
		sign = -1;
	}
	cord.ystep = mlx->player_y - (mlx->player_x - cord.xstep) * tan(ray_angle);
	mlx->dx = sign * TILE_SIZE;
	mlx->dy = sign * TILE_SIZE * tan(ray_angle);
	while (true)
	{
		if ((mlx->is_ray_facing_left && \
				has_wall(mlx, cord.xstep - TILE_SIZE, cord.ystep)) || \
			(!mlx->is_ray_facing_left && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += mlx->dx;
		cord.ystep += mlx->dy; 
	}
	return (cord);
}
