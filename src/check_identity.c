/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:55:26 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 16:33:41 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

/* FUNCTION TO READ LINE AND RETURNS IT IN A SINGLE LINE*/

void	hadik(char **str, char *rawmap, int j)
{
	int	i;

	(void)j;
	i = -1;
	if (i < 7)
	{
		arr_free(str);
		free(rawmap);
		exit(1);
	}
}

char	*read_file(char *filename)
{
	char	*str;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	if (!str)
		throw_err_2("Error\nFile is empty\n");
	line = ft_strdup("");
	if (!line)
		return (free(str), NULL);
	while (str)
	{
		tmp = line;
		line = ft_strjoin(line, str);
		free(str);
		free(tmp);
		str = get_next_line(fd); 
	}
	close(fd);
	return (line);
}

/* CHECK IF THE LINE IS ONLY SPACES AND TABS */

int	only(char *line, int c, int d)
{
	int	i;

	i = 0;
	while ((line[i] == c || line[i] == d) && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

/* TAKING THE LINE FROM READ_FILE AND TRIMMING THE NONE EMPTY LINES WITH 
' ' & '\t' AND ASSINGNED IT TO **char, ALL OF THAT AFTER SPLITTING IT '\n' */
char	**splimed_key_value_6(char *filename)
{
	char	**splimed_str;
	char	**str;
	char	*rawmap;
	int		i;
	int		j;

	j = 0;
	i = 0;
	rawmap = read_file(filename);
	if (!rawmap)
		return (NULL);
	str = ft_split(rawmap, '\n');
	if (!str)
		return (free(rawmap), NULL);
	splimed_str = (char **)ft_calloc(sizeof(char *), 7);
	while (str[i] != NULL && j < 6)
	{
		if (only(str[i], '\t', ' ') == 1)
			splimed_str[j++] = ft_strtrim(str[i], " \t");
		i++;
	}
	// xhadik(str, rawmap, j);
	return (free(rawmap), arr_free(str), splimed_str);
}

char	*ft_half_strtrim(char const *s1, char const *set)
{
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
	{
		s1++;
		if (*s1 == 32 || *s1 == '\t')
		{
			s1++;
			while (*s1 == 32 || *s1 == '\t')
				s1++;
			break ;
		}
	}
	return (ft_substr((char *)s1, 0, ft_strlen((char *)s1)));
}
