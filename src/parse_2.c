/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:50 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 16:59:40 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	all_white(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	end(char **map, char *file_name)
{
	int	e;

	if (!file_name || !map)
		return (0);
	e = 0;
	while (map[e])
		e++;
	e--;
	while (map[e] && all_white(map[e]))
		e--;
	return (e);
}

int skip_part1(char **tab)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (tab[++i] && c < 6)
	{
		if ((tab[i][0] == ' ' || tab[i][0] == '\t') && !all_white(tab[i]))
			c++;
		else if (tab[i][0] != '\n' && ft_strlen(tab[i]) >= 1)
			c++;
	}
	if (all_white(tab[i]))
		while (tab[i] && all_white(tab[i]))
			i++;
	return (i);
}

int	len2darray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void put_map(char **map, char *file_name)
{
	int	i;
	int	j;

	(void)file_name;
	i = skip_part1(map);
	info_path->info->map = ft_calloc(sizeof(char *), 
			((len2darray(map) - i) + 1));
	j = 0;
	while (map[i])
	{
		if (!map[i][0])
			i++;
		else
			info_path->info->map[j++] = ft_strdup(map[i++]);
	}
	info_path->info->map[j] = NULL;
	i = 0;
	free_(map);
}