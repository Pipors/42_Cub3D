/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:43:57 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 17:44:37 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	hook_key(void *arg)
{
	t_info	*map;
	double	target_x;
	double	target_y;

	map = (t_info *)arg;
	target_x = 0;
	target_y = 0;
	rgb(map);
	hooks(map, &target_x, &target_y);
	protection(map);
	problem(map, &target_x, &target_y);
	loop_ray(map);
}

void	text(t_info *map, char *filename)
{
	const char	*first;
	const char	*second;
	const char	*third;
	const char	*fourth;

	first = valid_first(map, filename);
	second = valid_second(map, filename);
	third = valid_third(map, filename);
	fourth = valid_fourth(map, filename);
	map->tex_north = mlx_load_png(first);
	map->tex_south = mlx_load_png(second);
	map->tex_west = mlx_load_png(third);
	map->tex_east = mlx_load_png(fourth);
	if (!map->tex_north || !map->tex_south || !map->tex_west || !map->tex_east)
		throw_err_2("CHUUUF A WELD LHAJ KIDIR\n");
}

void	init(t_info *map, char *filename)
{
	text(map, filename);
	map->width = HEIGHT;
	map->height = WIDTH;
	map->mlx = mlx_init(map->width, map->height, "CUB3D", 0);
	if (!map->mlx) 
		throw_err_2("Failed to initialize MLX\n");
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (!map->img)
	{
		fprintf(stderr, "Failed to create new image\n");
		mlx_terminate(map->mlx);
		return ;
	}
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
	{
		fprintf(stderr, "Failed to put image to window\n");
		mlx_delete_image(map->mlx, map->img);
		mlx_terminate(map->mlx);
		return ;
	}
	map->rows = ft_strlen(map->map[0]);
	map->cols = lenofmap(map->map);
	mlx_loop_hook(map->mlx, hook_key, map);
	mlx_loop(map->mlx);
}
