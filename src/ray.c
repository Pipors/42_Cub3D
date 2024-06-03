/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/06/03 17:40:28 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	isdown(double angle)
{
	if (angle >= 0 && angle <= M_PI)
		return (1);
	return (0);
}

int	isright(double angle)
{
	if (angle <= M_PI / 2.0 || angle >= 1.5 * M_PI)
		return (1);
	return (0);
}

void my_mlx_texture_to_image(t_info* map)
{
	uint8_t* pixelx;
	uint8_t* pixeli;
	double ok;
	double x_calc = (modf((map->inter.xstep) / TILE_SIZE, &ok)) * TILE_SIZE;
	double y_calc = (modf((map->inter.ystep) / TILE_SIZE, &ok)) * TILE_SIZE;
	mlx_texture_t* photos = map->tex1;
	double x_tex, y_tex;
	x_tex = 0;
	y_tex = 0;
	double start_y;
	double y_plus =   photos->height / (map->y_wall2 - map->y_wall1);

	if((map->y_wall2 - map->y_wall1) >= map->height)
		start_y =((map->y_wall2 - map->y_wall1) / 2 - map->height / 2);
	else
		start_y = 0;
	if (map->is_ray_facing_left && map->inter.is_vertical)
	{
		photos = map->tex1;
		x_tex = (y_calc * photos->width) / TILE_SIZE;
		y_tex = start_y * y_plus;
	}
	else if(map->is_ray_facing_up && !map->inter.is_vertical)
	{
		photos = map->tex2;
		x_tex = (x_calc * photos->width) / TILE_SIZE;
		y_tex = start_y * y_plus;
	}
	else if(!map->is_ray_facing_left && map->inter.is_vertical)
	{
		photos = map->tex3;
		x_tex = (y_calc * photos->width) / TILE_SIZE;
		y_tex = start_y * y_plus;
	}
	else if(!map->is_ray_facing_up && !map->inter.is_vertical)
	{
		photos = map->tex4;
		x_tex = (x_calc * photos->width) / TILE_SIZE;
		y_tex = start_y * y_plus;
	}
	double x_img = map->x_wall1;
	double y_img;
		y_img = map->y_wall1 + start_y;
	while (y_tex < photos->height && y_img < map->y_wall2 - start_y)
	{
		if (((y_tex * photos->width) + x_tex) * photos->bytes_per_pixel > 0 &&
			(((y_tex * photos->width) + x_tex) * photos->bytes_per_pixel < (photos->width * photos->height) * photos->bytes_per_pixel) 
			&& ((y_img * map->img->width) + x_img) * photos->bytes_per_pixel > 0
			&& (((y_img * map->img->width) + x_img) * photos->bytes_per_pixel < (map->img->width * map->img->height) * photos->bytes_per_pixel))
		{
			pixelx = &photos->pixels[(((int)y_tex * photos->width) + (int)x_tex) * photos->bytes_per_pixel];
			pixeli = &map->img->pixels[(((int)y_img * map->img->width) + (int)x_img) * photos->bytes_per_pixel];
			ft_memmove(pixeli, pixelx,  photos->bytes_per_pixel);
		}
		y_tex += y_plus;
		y_img++;
	}
}

void    pos_player(t_info *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'W')
				map->angle = M_PI;
			if (map->map[i][j] == 'E')
				map->angle = 0;
			if (map->map[i][j] == 'S')
				map->angle = M_PI / 2;
			if (map->map[i][j] == 'N')
				map->angle = 3 * M_PI / 2;
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

void	var_init(t_info *info)
{
	info->viewangle = FOV * (M_PI / 180);
	info->player.speedretate = SPEED_R * (M_PI / 180);
	info->player.speedmove = (CUBE * SPEED_M) / 20 ;
	info->player.dirturn = 0;
	info->player.dirwalk = 0;
	info->rad = M_PI / 180;
}

int	lenofmap(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

t_cord	smallest(t_info *mlx, t_cord c1, t_cord c2)
{
	float	d1;
	float	d2;

	d1 = sqrt((c1.xstep - mlx->player_x) * (c1.xstep - mlx->player_x) + \
				(c1.ystep - mlx->player_y) * (c1.ystep - mlx->player_y));
	d2 = sqrt((c2.xstep - mlx->player_x) * (c2.xstep - mlx->player_x) + \
				(c2.ystep - mlx->player_y) * (c2.ystep - mlx->player_y));
	if (d1 < d2)
	{
		mlx->dis = d1;
		c1.is_vertical = false;
		return (c1);
	}
	mlx->dis = d2;
	c2.is_vertical = true;
	return (c2);
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
	const float dx = sign * TILE_SIZE / tan(ray_angle);
	const float dy = sign * TILE_SIZE;
	while (true)
	{
		if ((mlx->is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep - TILE_SIZE)) || \
			(!mlx->is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += dx;
		cord.ystep += dy;
	}
	return (cord);
}

t_cord	vertical_intersection(t_info *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;

	mlx->is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	cord.xstep = (int) (1 + mlx->player_x / TILE_SIZE) * TILE_SIZE;
	if (mlx->is_ray_facing_left)
	{
		cord.xstep -= TILE_SIZE;
		sign = -1;
	}
	cord.ystep = mlx->player_y - (mlx->player_x - cord.xstep) * tan(ray_angle);
	const float dx = sign * TILE_SIZE;
	const float dy = sign * TILE_SIZE * tan(ray_angle);
	while (true)
	{
		if ((mlx->is_ray_facing_left && \
				has_wall(mlx, cord.xstep - TILE_SIZE, cord.ystep)) || \
			(!mlx->is_ray_facing_left && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += dx;
		cord.ystep += dy; 
	}
	return (cord);
}

void drawLine(t_info *map, int x1, int y1, int x2, int y2, uint32_t color)
{
	float dx, dy, step, x, y;
	int i;

	dx = x2 - x1;
	dy = y2 - y1;
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = x1;
	y = y1;
	i = 0;
	while (i <= step)
	{
		if (x > 0 && x < map->width && y > 0 && y < map->height)
			mlx_put_pixel(map->img, (int)x, (int)y, color); 
		x += dx;
		y += dy;
		i++;
	}
}

void	drawalls(t_info *map, double i)
{
	map->x_wall1 = i;
	map->x_wall2 = i;
	map->y_wall1 = (map->height / 2) - \
			((map->height / 2) / map->dis) * TILE_SIZE;
	map->y_wall2 = (map->height / 2) + \
			((map->height / 2) / map->dis) * TILE_SIZE;
	my_mlx_texture_to_image(map);
}

double	deg2rad(double degrees)
{
	return	(degrees * (M_PI / 180.0));
}
void hook_key(void *arg)
{    
	t_info *map = (t_info*)arg;
	double target_x = 0;
	double target_y = 0;
	int		i;
	int		j;

	i = 0;
	while (i < (map->height / 2))
	{
		j = 0;
		while (j < map->width)
		{
			mlx_put_pixel(map->img, j, i, \
				ft_pixel(map->_f[0], map->_f[1], map->_f[2], map->alpha));
			j++;
		}
		i++;
	}
	i = (map->height / 2);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_put_pixel(map->img, j, i, \
			ft_pixel(map->_c[0], map->_c[1], map->_c[2], map->alpha));
			j++;
		}
		i++;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
	{
		target_x += PLAYER_SPEED * cos(map->angle);
		target_y += PLAYER_SPEED * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
	{
		target_x -= PLAYER_SPEED * cos(map->angle);
		target_y -= PLAYER_SPEED * sin(map->angle);	
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
	{
		target_y -= PLAYER_SPEED * cos(map->angle);
		target_x += PLAYER_SPEED * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
	{
		target_y += PLAYER_SPEED * cos(map->angle);
		target_x -= PLAYER_SPEED * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->angle += deg2rad(2.5);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT)) 
		map->angle -= deg2rad(2.5);
	if (map->angle >= 2 * M_PI)
		map->angle -= 2 * M_PI;
	else if (map->angle < 0)
		map->angle += 2 * M_PI;	
	int map_x = ((map->player_x + (target_x * 2) ) / TILE_SIZE) ;
	int map_y = ((map->player_y + (target_y * 2) ) / TILE_SIZE) ;
	if (map_x > 0 && map_x < get_width() && map_y > 0 && map_y < get_height()
		&& map->map[map_y][map_x] == '0')
	{
		map->player_x += target_x;
		map->player_y += target_y;
	}
	draw_map(map);
	map->angle_fov = map->angle - deg2rad(FOV / 2);
	double k = 0;
	double disrays = deg2rad(FOV)/ map->width;
	while (k < map->width)
	{
		if (map->angle_fov > 2 * M_PI)
			map->angle_fov -= 2 * M_PI;
		if (map->angle_fov < 0)
			map->angle_fov += 2 * M_PI;
		t_cord h =  horizontal_intersection(map, map->angle_fov);
		h.is_vertical = false;
		t_cord v = vertical_intersection(map, map->angle_fov);
		v.is_vertical = true;   
		map->inter = smallest(map, h, v);
		map->dis *= cos(map->angle - map->angle_fov);
		// direct(map);
		drawLine(map, map->player_x / ZOOM, 
			map->player_y / ZOOM, map->inter.xstep / ZOOM, 
			map->inter.ystep / ZOOM, 0xFF000FFF);
		drawalls(map, k);
		map->angle_fov += disrays;
		k++;
	}
}

void key_hook(mlx_key_data_t keydata, void* param)
{
	(void)param;
	if (keydata.key == MLX_KEY_A 
		&& keydata.action == MLX_RELEASE 
		&& keydata.modifier == MLX_CONTROL)
		puts("Gotta grab it all!");
}

int	get_height(void)
{
	int	i;

	i = 0;
	while (info_path->info->map[i])
		i++;
	return (i);
}

int get_width(void)
{
	int	i;
	int	j;
	int	max_width;

	i = 0;
	j = 0;
	max_width = 0;
	while (info_path->info->map[i])
	{
		j = 0;
		while (info_path->info->map[i][j])
			j++;
		if (j > max_width)
			max_width = j;
		i++;
	}
	return (max_width);
}

void draw_map(void *param)
{
	t_info *info = (t_info *)param;
	int x, y, i, j;
	int pixel_x, pixel_y;
	int width = get_width();
	int height = get_height();

	if (!info || !info->map || !info->img)
	{
		fprintf(stderr, "Invalid parameters or uninitialized map/image\n");
		return ;
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			char tile = info->map[i][j];
			uint32_t color;
	
				if (tile == '1')
					color = 0x000000FF; // Black color
				else 
					color = 0xFFFFFFFF; // White color
			for (y = 0; y < TILE_SIZE; y++)
			{
				for (x = 0; x < TILE_SIZE; x++)
				{
					pixel_x = (j * TILE_SIZE + x) / ZOOM;
					pixel_y = (i * TILE_SIZE + y) / ZOOM;

					
					// Check if the pixel is on the border of the tile
					if((pixel_x > 0 && pixel_x < info->width && pixel_y > 0 && pixel_y < info->height))
					{
						if (x == 0 || x == TILE_SIZE - 1 || y == 0 || y == TILE_SIZE - 1 )
							mlx_put_pixel(info->img, pixel_x, pixel_y, 0x00FF00FF);
						else
							mlx_put_pixel(info->img, pixel_x, pixel_y, color);			
					}
				}
			} 
		}
	}
	for (i = 0; i < TILE_PLAYER_SIZE; ++i)
	{
		for (j = 0; j < TILE_PLAYER_SIZE; ++j)
		{
			double x = info->player_x + i;
			double y = info->player_y + j;
			if (x > 0 && x < info->width && y > 0 && y < info->height)
				mlx_put_pixel(info->img, x, y, 0x0000FFFF);
		}
	}
}

void init(t_info *map)
{
	map->tex1 = mlx_load_png("./marooccccc.png");
	map->tex2 = mlx_load_png("./palestineflag.png");
	map->tex3 = mlx_load_png("./masjiid.png");
	map->tex4 = mlx_load_png("./gofiya.png");
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
