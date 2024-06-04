/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:14:11 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 19:48:09 by aatbir           ###   ########.fr       */
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
# include <stdlib.h>
# include <string.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include "../MLX/MLX42.h"

# define CUBE 10
# define TILE_PLAYER_SIZE 1
# define TILE_SIZE 64
# define WIDTH 1222
# define HEIGHT 1000
# define MSIZE 170
# define PLAYER_SPEED 2
# define SPEED_R 3
# define M_SPEED_R 1
# define SPEED_M 2
# define FOV 60
# define ZOOM 3
# define PIXEL_SIZE 50

// Initialize the player with default values

typedef struct s_cord
{
	double	xstep;
	double	ystep;
	bool	is_vertical;
	bool	down;
	bool	right;
}	t_cord;

typedef struct s_info
{
	bool			is_ray_facing_up;
	bool			is_ray_facing_left;
	double			angle;
	double			angle_fov;
	double			dis;
	double			k;
	double			player_x;
	double			player_y;
	double			rad;
	double			view;
	double			viewangle;
	double			x_wall1;
	double			x_wall2;
	double			y_wall1;
	double			y_wall2;
	char			pos;
	char			*addr;
	char			*first_info;
	char			*second_info;
	char			*third_info;
	char			*fourth_info;
	char			*first_color;
	char			*second_color;
	char			**map;
	float			dx;
	float			dy;
	float			x;
	float			y;
	int				alpha;
	int				bits_per_pixel;
	int				cols;
	int				endian;
	int				line_length;
	int				nbr_rays;
	int				width;
	int				height;
	int				_f[3];
	int				_c[3];
	int				rows;
	int				x_tex;
	int				y_tex;
	int				y_start;
	int				y_end;
	int				x_map;
	int				y_map;
	void			*win;
	mlx_texture_t	*tex_north;
	mlx_texture_t	*tex_south;
	mlx_texture_t	*tex_west;
	mlx_texture_t	*tex_east;
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_cord			inter;
}	t_info;

typedef struct s_map
{
	t_info	*info;
	int		wid;
	int		hei;
}	t_map;

t_map	*g_info_path;

double		pow_2(double x);
double		deg2rad(double degrees);

int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

char		*ft_strtrim(char const *s1, char const *set);
char		*valid_first_info(t_info *info, char *filename);
char		*valid_second_info(t_info *info, char *filename);
char		*valid_third_info(t_info *info, char *filename);
char		*valid_fourth_info(t_info *info, char *filename);
char		*ft_strtrim(char const *s1, char const *set);
char		**splimed_key_value_6(char *filename);
char		**store_get_info_in_array(t_info *info, char *filename);
char		*valid_first_info(t_info *info, char *filename);
char		*ft_half_strtrim(char const *s1, char const *set);
char		**textures(void);
char		*take_first_string(char *line);
char		*start_with(char *first_word, char *target, size_t size);
char		*read_file(char *filename);

const char	*valid_first(t_info *info, char *filename);
const char	*valid_second(t_info *info, char *filename);
const char	*valid_third(t_info *info, char *filename);
const char	*valid_fourth(t_info *info, char *filename);

int			*split_first_color(t_info *info, char *filename);
int			compare_dup_text(t_info *info, char *filename);
int			compare(char *s1, char *s2);
int			is_valid_textures(t_info *info, char *filename);
int			get_height(void);
int			get_width(void);
int			is_closed(char c);
int			check_content(void);
int			check_first_last(void);
int			all_white(char *str);
int			empty_line(void);
int			check_existance(char c);
int			lines_number(char *str);
int			map_len(void);
int			lenofmap(char **arr);
int			only(char *line, int c, int d);
int			check_if_only_numbers(char **str);
int			valid_rgb_f(t_info *info, char *filename);
int			valid_rgb_c(t_info *info, char *filename);

void		arr_free(char **s);
void		check_get_info(t_info	*info, char *filename);
void		check_dir(t_info *map, int i, int j);
void		check_first_path(t_info *info, char **str, int i);
void		check_second_path(t_info *info, char **str, int i);
void		check_third_path(t_info *info, char **str, int i);
void		check_fourth_path(t_info *info, char **str, int i);
void		check_second_color(t_info *info, char **str, int i);
void		check_first_color(t_info *info, char **str, int i);
void		draw_map(void *param);
void		drawalls(t_info *map, double i);
void		free_arr(char **ar);
void		*free_(char **file);
void		ft_free_info(t_info *info);
void		hooks(t_info *map, double *target_x, double *target_y);
void		init(t_info *map, char *filename);
void		loop_ray(t_info *map);
void		my_mlx_texture_to_image(t_info*map, double x_percent);
void		parsing(t_info *info, char *filename);
void		player_pos(void);
void		pos_player(t_info *map);
void		problem(t_info *map, double *target_x, double *target_y);
void		protection(t_info *map);
void		put_map(char **map, char *file_name);
void		rgb(t_info *map);
void		rotation(t_info *map);
void		_short(t_info *map, double x_percent, mlx_texture_t	*tex);
void		throw_err_2(char *err_msg);

t_cord		smallest(t_info *mlx, t_cord c1, t_cord c2);
t_cord		vertical_intersection(t_info *mlx, float ray_angle);
t_cord		horizontal_intersection(t_info *mlx, float ray_angle);
t_info		*get_info(t_info *info, char *filename);

#endif