/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:34:46 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 17:56:35 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	drawalls(t_info *map, double i)
{
	int	wall_height;

	wall_height = (int)(30000.0 / map->dis);
	map->x_wall1 = i;
	map->x_wall2 = i;
	map->y_wall1 = map->height / 2 - wall_height / 2;
	map->y_wall2 = wall_height;
	my_mlx_texture_to_image(map, 0);
}

double	deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

void	rgb(t_info *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (map->height / 2))
	{
		j = -1;
		while (++j < map->width)
			mlx_put_pixel(map->img, j, i, \
				ft_pixel(map->_c[0], map->_c[1], map->_c[2], map->alpha));
	}
	i = (map->height / 2);
	while (i < map->height)
	{
		j = -1;
		while (++j < map->width)
			mlx_put_pixel(map->img, j, i, \
			ft_pixel(map->_f[0], map->_f[1], map->_f[2], map->alpha));
		i++;
	}
}

void	rotation(t_info *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->angle += deg2rad(2.5);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT)) 
		map->angle -= deg2rad(2.5);
}

void	hooks(t_info *map, double *target_x, double *target_y)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
	{
		*target_x += 2 * cos(map->angle);
		*target_y += 2 * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
	{
		*target_x -= 2 * cos(map->angle);
		*target_y -= 2 * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
	{
		*target_y -= 2 * cos(map->angle);
		*target_x += 2 * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
	{
		*target_y += 2 * cos(map->angle);
		*target_x -= 2 * sin(map->angle);
	}
	rotation(map);
}
