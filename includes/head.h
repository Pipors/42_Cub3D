/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:14:11 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 18:48:20 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>
# include <fcntl.h>
#include <stdlib.h>
#include <string.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include "../MLX/MLX42.h"


#define CUBE 10
# define TILE_PLAYER_SIZE 1
# define TILE_SIZE 64
#define WIDTH 1000
#define HEIGHT 800
# define MSIZE 170
#define PLAYER_SPEED 2
# define SPEED_R 3
# define M_SPEED_R 1
# define SPEED_M 2
# define FOV 60
# define ZOOM 3


# define PIXEL_SIZE 50



// Initialize the player with default values


typedef struct s_cord
{
    double xstep;
    double ystep;
	bool	is_vertical;
	bool	down;
	bool	right;
} t_cord;

typedef struct s_ray
{
	double	angle;
	double	dis;
	double	x;
	double	y;
	int		up;
	int		down;
	int		left;
	int		right;
	double	hwallx;
	double	hwally;
	double	vwallx;
	double	vwally;
	double	hdis;
	double	vdis;
	int		iswallh;
	int		iswallv;
	double	hx;
	double	hy;
	double	hxstep;
	double	hystep;
	double	hxnext;
	double	hynext;
	double	vx;
	double	vy;
	double	vxstep;
	double	vystep;
	double	vxnext;
	double	vynext;
	int		v;
	int		h;
}			t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dirturn;
	double	dirwalk;
	double	dirwalkx;
	double	alpha;
	double	speedmove;
	double	speedretate;
	double	speedretate_m;
}		t_player;

typedef struct s_info
{
	bool	is_ray_facing_up;
	bool	is_ray_facing_left;
    double angle_fov;
	int width;
	int height;
	char	*first_info;
	char	*second_info;
	char	*third_info;
	char	*fourth_info;
	char	*first_color;
	char	*second_color;
	double	view;
	int		_f[3];
	int		_c[3];
	float		x;
	int cols;
	float		y;
	char 	pos;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	double	rad;
	int		endian;
	void 	*win;
	char	**map;
	double		viewangle;
	double	dis;
	mlx_texture_t	*tex_north;
	mlx_texture_t	*tex_south;
	mlx_texture_t	*tex_west;
	mlx_texture_t	*tex_east;
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_player	player;
	double		player_x;
	double		player_y;
	int			nbr_rays;
	int rows;
		t_ray		*ray;
	double	angle;
    double x_wall1;
	double x_wall2;
	double y_wall1;
	double y_wall2;
	t_cord inter;
	int reversedR_F;
    int reversedG_F;
    int reversedB_F;
	int reversedR_C;
    int reversedG_C;
    int reversedB_C;
	int alpha;
	float dx;
	float dy;
	int x_tex;
	int y_tex;
	int y_start;
	int y_end;
	int x_map;
	int y_map;
	double k;
}	t_info;

// typedef struct s_player
// {
// 	float	x;
// 	float	y;
// 	float	arr_str;
// 	char	_snew;
// }	t_player;

typedef struct s_map
{
	t_info	*info;
	int		wid;
	int		hei;
}	t_map;

t_map *info_path;

char	*read_file(char *filename);
void	ft_free_info(t_info *info);

t_info	*get_info(t_info *info, char *filename);
void	throw_err_2(char *err_msg);

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

int		only(char *line, int c, int d);
int		check_if_only_numbers(char **str);
int		valid_rgb_f(t_info *info, char *filename);
int		valid_rgb_c(t_info *info, char *filename);
char	**splimed_key_value_6(char *filename);


char	*ft_strtrim(char const *s1, char const *set);
char	*valid_first_info(t_info *info, char *filename);
char	*valid_second_info(t_info *info, char *filename);
char	*valid_third_info(t_info *info, char *filename);
char	*valid_fourth_info(t_info *info, char *filename);
int		*split_first_color(t_info *info, char *filename);
const char	*valid_first(t_info *info, char *filename);
const char	*valid_second(t_info *info, char *filename);
const char	*valid_third(t_info *info, char *filename);
const char	*valid_fourth(t_info *info, char *filename);
char		*ft_strtrim(char const *s1, char const *set);
char	**textures(void);
int		compare_dup_text(t_info *info, char *filename);
void	parsing(t_info *info, char *filename);
int		compare(char *s1, char *s2);
void	check_first_path(t_info *info, char **str, int i);
void	check_second_path(t_info *info, char **str, int i);
void	check_third_path(t_info *info, char **str, int i);
void	check_fourth_path(t_info *info, char **str, int i);
void	check_second_color(t_info *info, char **str, int i);
void	check_first_color(t_info *info, char **str, int i);
void	arr_free(char **s);
t_cord	vertical_intersection(t_info *mlx, float ray_angle);
t_cord	horizontal_intersection(t_info *mlx, float ray_angle);
char	**store_get_info_in_array(t_info *info, char *filename);
char	*valid_first_info(t_info *info, char *filename);
char	*ft_half_strtrim(char const *s1, char const *set);
void	parsing(t_info *info, char *filename);
char	*take_first_string(char *line);
char	*start_with(char *first_word, char *target, size_t size);
int		is_valid_textures(t_info *info, char *filename);
void check_get_info(t_info	*info, char *filename);
void	player_pos(void);
double	deg2rad(double degrees);
void	rgb(t_info *map);
int get_height(void);
int get_width(void);
void _short(t_info *map, double x_percent, mlx_texture_t	*tex);
void check_dir(t_info *map, int i, int j);
void draw_map(void *param);
int32_t reverseRGB(char* input);
void	drawalls(t_info *map, double i);
void pos_player(t_info *map);
int32_t	run_game(void);
void rotation(t_info *map);
void	problem(t_info *map, double *target_x, double *target_y);
void	loop_ray(t_info *map);
void	protection(t_info *map);
void hooks(t_info *map, double *target_x, double *target_y);
int	is_closed(char c);
void init(t_info *map, char *filename);
int check_content(void);
int	check_first_last(void);
void put_map(char **map, char *file_name);
int	all_white(char *str);
void	*free_(char **file);
void	free_arr(char **ar);
int empty_line(void);
int	check_existance(char c);
int	lines_number(char *str);
int	map_len(void);
void	my_mlx_texture_to_image(t_info*map, double x_percent);
t_cord	smallest(t_info *mlx, t_cord c1, t_cord c2);
double	pow_2(double x);
int	lenofmap(char **arr);
#endif