/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:14:00 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 17:18:17 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	is_closed(char c)
{
	(void)c;
	// ;
	// int i = 0;
	// int j = 0;
	int len_map = map_len();
	// int row_length;
	if (len_map == 0)
		return (0); 
	return (1);
}

int	check_first_last(void)
{
	int	i;
	int	e;

	i = -1;
	while (info_path->info->map[0][++i])
	{
		if (info_path->info->map[0][i] == '0' 
			|| info_path->info->map[0][i] == info_path->info->pos)
			return (0);
	}
	e = map_len() - 1;
	i = -1;
	while (info_path->info->map[e][++i])
	{
		if (info_path->info->map[e][i] == '0' 
			|| info_path->info->map[e][i] == info_path->info->pos)
			return (0);
	}
	return (1);
}

int	checker_map1(char *file_name)
{
	put_map(ft_split(read_file(file_name), '\n'), file_name);
	if (!empty_line())
		return (0);
	if (!check_content())
		return (0);
	player_pos();
	if (!check_first_last())
		return (0);
	if (!is_closed(info_path->info->pos))
	{
		printf("%c\n", info_path->info->pos);
		return (0);
	}
	printf("MapIsGood\n");
	return (1);
}

void	parsing(t_info *info, char *filename)
{
	compare_dup_text(info, filename);
	is_valid_textures(info, filename);
	valid_rgb_f(info, filename);
	valid_rgb_c(info, filename);
	if (!checker_map1(filename))
		throw_err_2("MapIsBAD🆘\n");
}
