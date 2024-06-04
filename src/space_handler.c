/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:13:15 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 18:54:02 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || !n)
		return (dest);
	while (i < n)
	{
		(*((char *)dest + i)) = (*((char *)src + i));
		i++;
	}
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = len;
	if (i > ft_strlen(s))
	{
		str = malloc((ft_strlen(s) + 1) * sizeof(char));
		i = ft_strlen(s) - start;
	}
	else
		str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	ft_memcpy(str, s + start, i);
	str[i] = '\0';
	return (str);
}

int32_t	ft_pixel(int r, int g, int b, int alpha)
{
	return ((alpha << 24) | (r << 16) | (g << 8) | b);
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
