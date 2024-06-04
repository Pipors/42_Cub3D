/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:27:03 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 17:30:10 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	my_mlx_texture_to_image(t_info*map, double x_percent)
{
	mlx_texture_t	*tex;
	t_cord			inter;

	inter = map->inter;
	if (!inter.is_vertical)
	{
		x_percent = inter.xstep / TILE_SIZE - ((int) inter.xstep / TILE_SIZE);
		tex = map->tex_north;
		if (map->player_y - inter.ystep < 0)
		{
			tex = map->tex_south;
			x_percent = 1.0 - x_percent;
		}
	}
	else
	{
		x_percent = inter.ystep / TILE_SIZE - ((int) inter.ystep / TILE_SIZE);
		tex = map->tex_east;
		if (map->player_x - inter.xstep > 0)
		{
			tex = map->tex_west;
			x_percent = 1.0 - x_percent;
		}
	}
	_short(map, x_percent, tex);
}

void	pos_player(t_info *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			check_dir(map, i, j);
			if (ft_strchr("NSWE", map->map[i][j]))
			{
				map->player_x = (j + 0.5) * TILE_SIZE - TILE_PLAYER_SIZE / 2;
				map->player_y = (i + 0.5) * TILE_SIZE - TILE_PLAYER_SIZE / 2;
				map->map[i][j] = '0';
				return ;
			}
		}
	}
}

int	lenofmap(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

double	pow_2(double x)
{
	return (x * x);
}

t_cord	smallest(t_info *mlx, t_cord c1, t_cord c2)
{
	float	d1;
	float	d2;

	d1 = pow_2(c1.xstep - mlx->player_x) + pow_2(c1.ystep - mlx->player_y);
	d2 = pow_2(c2.xstep - mlx->player_x) + pow_2(c2.ystep - mlx->player_y);
	if (d1 < d2)
	{
		mlx->dis = sqrt(d1);
		c1.is_vertical = false;
		return (c1);
	}
	mlx->dis = sqrt(d2);
	c2.is_vertical = true;
	return (c2);
}
