/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:31:52 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 17:13:02 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

char	**textures(void)
{
	char	**text;

	text = (char **)malloc(sizeof(char *) * 7);
	if (!text)
		return (NULL);
	text[0] = ft_strdup("NO");
	text[1] = ft_strdup("SO");
	text[2] = ft_strdup("EA");
	text[3] = ft_strdup("WE");
	text[4] = ft_strdup("F");
	text[5] = ft_strdup("C");
	text[6] = NULL;
	return (text);
}

int	compare(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, 2));
}

void	*free_(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
		free(file[i]);
	free(file);
	return (NULL);
}

int	compare_dup_text(t_info *info, char *filename)
{
	char	**str;

	str = store_get_info_in_array(info, filename);
	if (!str)
		return (0);
	if ((compare(str[0], str[1]) == 0) || (compare(str[0], str[2]) == 0) 
		|| (compare(str[0], str[3]) == 0) || (compare(str[0], str[4]) == 0) 
		|| (compare(str[0], str[5]) == 0) || (compare(str[1], str[2]) == 0) 
		|| (compare(str[1], str[3]) == 0) || (compare(str[1], str[4]) == 0) 
		|| (compare(str[1], str[5]) == 0) || (compare(str[2], str[3]) == 0) 
		|| (compare(str[2], str[4]) == 0) || (compare(str[2], str[5]) == 0) 
		|| (compare(str[3], str[4]) == 0) || (compare(str[3], str[5]) == 0) 
		|| (compare(str[4], str[5]) == 0))
		throw_err_2("Error\nDuplicated Identifier\n");
	return (arr_free(str), 0);
}

int	lines_number(char *str)
{
	char	*s;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDWR);
	s = get_next_line(fd);
	while (s)
	{
		++i;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	return (i);
}
