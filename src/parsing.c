/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:14:00 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 19:47:13 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	is_close_1(int i, int j)
{
	if (g_info_path->info->map[i][j] == '0' 
		|| (g_info_path->info->map[i][j] == 'N' 
		||g_info_path->info->map[i][j] == 'W' 
		|| g_info_path->info->map[i][j] == 'S' 
		|| g_info_path->info->map[i][j] == 'E'))
	{
		if ((i == 0 || (size_t)j >= ft_strlen(g_info_path->info->map[i - 1])) 
			|| g_info_path->info->map[i - 1][j] == ' ' ||
			g_info_path->info->map[i - 1][j] == '\n')
			return (0);
		if ((!g_info_path->info->map[i + 1] 
				|| (size_t)j >= ft_strlen(g_info_path->info->map[i + 1]))
			|| g_info_path->info->map[i + 1][j] == ' ' || 
			g_info_path->info->map[i + 1][j] == '\n')
			return (0);
		if (i == 0 || g_info_path->info->map[i][j - 1] == ' ' || 
			g_info_path->info->map[i][j - 1] == '\n')
			return (0);
		if (!g_info_path->info->map[i][j + 1] || 
			g_info_path->info->map[i][j + 1] == ' ' || 
			g_info_path->info->map[i][j + 1] == '\n')
			return (0);
	}
	return (1);
}

int	is_close_2(char c, int i, int j)
{
	if (g_info_path->info->map[i][j] == c)
	{
		if ((g_info_path->info->map[i][j - 1] == ' '
			|| g_info_path->info->map[i][j - 1] == 0)
			|| (g_info_path->info->map[i][j + 1] == ' '
			|| g_info_path->info->map[i][j + 1] == 0)
			|| (g_info_path->info->map[i - 1][j] == ' '
			|| j + 1 >= (int)ft_strlen(g_info_path->info->map[i - 1]))
			|| (g_info_path->info->map[i + 1][j] == ' '
			|| j + 1 >= (int)ft_strlen(g_info_path->info->map[i + 1])))
			return (0);
	}
	return (1);
}

int	is_closed(char c)
{
	int	i;
	int	j;

	i = -1;
	while (g_info_path->info->map[++i] && i < map_len())
	{
		j = -1;
		if (g_info_path->info->map[i][0] == '0')
			return (0);
		while (g_info_path->info->map[i][++j])
		{
			if (is_close_1(i, j) == 0)
				return (0);
			if (is_close_2(c, i, j) == 0)
				return (0);
		}
	}
	return (1);
}

int	check_first_last(void)
{
	int	i;
	int	e;

	i = -1;
	while (g_info_path->info->map[0][++i])
	{
		if (g_info_path->info->map[0][i] == '0' 
			|| g_info_path->info->map[0][i] == g_info_path->info->pos)
			return (0);
	}
	e = map_len() - 1;
	i = -1;
	while (g_info_path->info->map[e][++i])
	{
		if (g_info_path->info->map[e][i] == '0' 
			|| g_info_path->info->map[e][i] == g_info_path->info->pos)
			return (0);
	}
	return (1);
}

void	free_arr(char **ar)
{
	int	i;

	i = -1;
	while (ar[++i])
		free(ar[i]);
	free(ar);
}
