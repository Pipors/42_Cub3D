/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:02:17 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 17:17:49 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	empty_line(void)
{
	int	i;

	i = 0;
	while (info_path->info->map[i])
	{
		if (all_white(info_path->info->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	player_num(void)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] == 'N' ||
				info_path->info->map[i][j] == 'S' ||
				info_path->info->map[i][j] == 'E' ||
				info_path->info->map[i][j] == 'W')
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
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] == c)
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
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] != '0' 
			&& info_path->info->map[i][j] != '1' 
			&& info_path->info->map[i][j] != '\n' 
			&& info_path->info->map[i][j] != 'N' 
			&& info_path->info->map[i][j] != 'S' 
			&& info_path->info->map[i][j] != 'E' 
			&& info_path->info->map[i][j] != 'W' 
			&& info_path->info->map[i][j] != ' ')
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
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] == 'N' 
				|| info_path->info->map[i][j] == 'S' 
				|| info_path->info->map[i][j] == 'E' 
				|| info_path->info->map[i][j] == 'W')
			{
				info_path->info->pos = info_path->info->map[i][j];
				info_path->info->x = i;
				info_path->info->y = j;
			}
		}
	}
}
