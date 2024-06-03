/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:14:40 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 17:17:28 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	is_valid_textures(t_info *info, char *filename)
{
	char	*first;
	char	*second;
	char	*third;
	char	*fourth;

	first = valid_first_info(info, filename);
	second = valid_second_info(info, filename);
	third = valid_third_info(info, filename);
	fourth = valid_fourth_info(info, filename);
	if (!first || !second || !third || !fourth)
	{
		free(first);
		free(second);
		free(third);
		free(fourth);
		throw_err_2("Error\nPath to texture is not found\n");
	}
	free(first);
	free(second);
	free(third);
	free(fourth);
	return (0);
}

int	map_len(void)
{
	int	i;

	i = 0;
	while (info_path->info->map[i])
		i++;
	return (i);
}

void	check_contour_right_left(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
			throw_err_2("the left wall is not fully 1 or space\n");
		i++;
	}
	i = 0;
	while (map[i])
	{
		len = strlen(map[i]);
		if (map[i][len - 1] != '1' && map[i][len - 1] != ' ')
		{
			throw_err_2("the right wall is not fully 1 or space\n");
		}
		i++;
	}
}

void	check_contour_up_down(char **map)
{
	int	j;

	j = 0;
	if (map[0])
	{
		while (map[0][j])
		{
			if (map[0][j] == '1' || map[0][j] == ' ')
				j++;
			else
				throw_err_2("the upper wall is not fully 1\n");
		}
	}
	j = 0;
	if (map[map_len() - 1])
	{
		while (map[map_len() - 1][j])
		{
			if (map[map_len() - 1][j] == '1' || map[map_len() - 1][j] == ' ')
				j++;
			else
				throw_err_2("the lower wall is not fully 1\n");
		}
	}
}
