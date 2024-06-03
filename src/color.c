/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:31:10 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 16:05:38 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	throw_err_1(char **str, char **fcolor, char *tmp)
{
	if (check_if_only_numbers(str) != 1)
	{
		free(tmp);
		arr_free(fcolor);
		arr_free(str);
		printf("Invalid RGB colors\n");
		exit(1);
	}
}

int	*split_first_color(t_info *info, char *filename)
{
	char	**fcolor;
	char	**just_rgb;
	char	*tmp;
	int		i;

	i = 0;
	info->alpha = 255;
	fcolor = store_get_info_in_array(info, filename);
	tmp = ft_half_strtrim(fcolor[4], "F\t ");
	if (!fcolor || !tmp)
		return (NULL);
	just_rgb = ft_split(tmp, ',');
	if (!just_rgb || just_rgb[0] == NULL || just_rgb[1] == NULL
		|| just_rgb[2] == NULL || just_rgb[3] != NULL)
		throw_err_2("RGB 'F' color is not written correctly");
	throw_err_1(just_rgb, fcolor, tmp);
	while (i < 3)
	{
		info->_f[i] = ft_atoi(just_rgb[i]);
		free(just_rgb[i]);
		i++;
	}
	return (free(just_rgb), arr_free(fcolor), free(tmp), info->_f);
}

int	*split_second_color(t_info *info, char *filename)
{
	char	**ccolor;
	char	**just_rgb;
	char	*tmp;
	int		i;

	i = 0;
	info->alpha = 255;
	ccolor = store_get_info_in_array(info, filename);
	tmp = ft_half_strtrim(ccolor[5], "C\t ");
	if (!ccolor || !tmp)
		return (NULL);
	just_rgb = ft_split(tmp, ',');
	if (!just_rgb || just_rgb[0] == NULL || just_rgb[1] == NULL || 
		just_rgb[2] == NULL || just_rgb[3] != NULL)
		throw_err_2("RGB 'C' color is not written correctly");
	throw_err_1(just_rgb, ccolor, tmp);
	while (i < 3)
	{
		info->_c[i] = ft_atoi(just_rgb[i]);
		free(just_rgb[i]);
		i++;
	}
	return (free(just_rgb), arr_free(ccolor), free(tmp), info->_c);
}

int	valid_rgb_f(t_info *info, char *filename)
{
	int	*f;
	int	i;

	i = 0;
	f = split_first_color(info, filename);
	if ((f[0] < 0 || f[0] > 255) 
		|| (f[1] < 0 || f[1] > 255) 
		|| (f[2] < 0 || f[2] > 255))
		throw_err_2("Error\nRGB 'F' color not in range");
	return (1);
}

int	valid_rgb_c(t_info *info, char *filename)
{
	int	*c;
	int	i;

	c = split_second_color(info, filename);
	i = 0;
	if ((c[0] < 0 || c[0] > 255) 
		|| (c[1] < 0 || c[1] > 255) 
		|| (c[2] < 0 || c[2] > 255))
		throw_err_2("Error\nRGB 'C' color not in range");
	return (1);
}
