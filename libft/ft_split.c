/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:29:54 by aatbir            #+#    #+#             */
/*   Updated: 2022/11/09 20:56:51 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_alloclist(char const *s1, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (!s || !s1)
		return (NULL);
	while (i < n)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_free(char **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free(s[j]);
		j++;
	}
	free(s);
	return (NULL);
}

size_t	wordlen(char const *s, int c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**del_s;
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	y = 0;
	del_s = (char **)malloc(sizeof(char *) * (wordlen(s, c) + 1));
	if (!del_s || !s)
		return (NULL);
	while (x < wordlen(s, c) && s[y] != '\0')
	{
		while (s[y] == c)
			y++;
		z = y;
		while (s[y] != c && s[y] != '\0')
			y++;
		del_s[x] = ft_alloclist(&s[z], y - z);
		if (del_s[x] == 0)
			return (ft_free(del_s));
		x++;
	}
	del_s[x] = NULL;
	return (del_s);
}
