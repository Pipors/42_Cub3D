/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:02:17 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 19:41:04 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	player_num(void)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (g_info_path->info->map[++i])
	{
		j = -1;
		while (g_info_path->info->map[i][++j])
		{
			if (g_info_path->info->map[i][j] == 'N' ||
				g_info_path->info->map[i][j] == 'S' ||
				g_info_path->info->map[i][j] == 'E' ||
				g_info_path->info->map[i][j] == 'W')
			{
				c++;
			}
		}
	}
	if (c != 1)
		return (0);
	return (1);
}

int	check_existance(char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (g_info_path->info->map[++i])
	{
		j = -1;
		while (g_info_path->info->map[i][++j])
		{
			if (g_info_path->info->map[i][j] == c)
				count++;
		}
	}
	if (!count)
		return (0);
	return (1);
}

int	check_content(void)
{
	int		i;
	int		j;

	i = -1;
	while (g_info_path->info->map[++i])
	{
		j = -1;
		while (g_info_path->info->map[i][++j])
		{
			if (g_info_path->info->map[i][j] != '0' 
			&& g_info_path->info->map[i][j] != '1' 
			&& g_info_path->info->map[i][j] != '\n' 
			&& g_info_path->info->map[i][j] != 'N' 
			&& g_info_path->info->map[i][j] != 'S' 
			&& g_info_path->info->map[i][j] != 'E' 
			&& g_info_path->info->map[i][j] != 'W' 
			&& g_info_path->info->map[i][j] != ' ')
				return (0);
		}
	}
	if (!player_num())
		return (0);
	return (1);
}

void	player_pos(void)
{
	int	i;
	int	j;

	i = -1;
	while (g_info_path->info->map[++i])
	{
		j = -1;
		while (g_info_path->info->map[i][++j])
		{
			if (g_info_path->info->map[i][j] == 'N' 
				|| g_info_path->info->map[i][j] == 'S' 
				|| g_info_path->info->map[i][j] == 'E' 
				|| g_info_path->info->map[i][j] == 'W')
			{
				g_info_path->info->pos = g_info_path->info->map[i][j];
				g_info_path->info->x = i;
				g_info_path->info->y = j;
			}
		}
	}
}
