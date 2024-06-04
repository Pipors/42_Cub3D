/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:39:52 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 19:41:04 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

char	**arrjoin(char **ar, char *line, int size)
{
	char	**rtrn;
	int		i;
	int		j;

	i = -1;
	if (!line)
		return (ar);
	rtrn = ft_calloc(sizeof(char *), (size + 2));
	while (ar[++i])
		rtrn[i] = ft_calloc(1, ft_strlen(ar[i]) + 1);
	i = -1;
	while (ar[++i])
	{
		j = -1;
		while (ar[i][++j])
			rtrn[i][j] = ar[i][j];
	}
	rtrn[i] = ft_strdup(line);
	free_arr(ar);
	free(line);
	return (rtrn);
}

char	**map_to_ar(int fd)
{
	char	**map;
	char	*line;
	int		i;

	map = ft_calloc(sizeof(char *), 1);
	line = get_next_line(fd);
	while (1)
	{
		i = 0;
		if (line == NULL)
			return (free_arr(map), NULL);
		while ((line[i] && line[i] == ' ') || line[i] == '\n')
			i++;
		if (line[i])
			break ;
		free(line);
		line = get_next_line(fd);
	}
	map = arrjoin(map, line, i++);
	while (line)
	{
		line = get_next_line(fd);
		map = arrjoin(map, &line[0], i++);
	}
	return (free(line), map);
}

int	checker_map1(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	put_map(map_to_ar(fd), file_name);
	if (!check_content())
		return (0);
	player_pos();
	if (!check_first_last())
		return (0);
	if (!is_closed(g_info_path->info->pos || !is_closed('0')))
		return (0);
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
