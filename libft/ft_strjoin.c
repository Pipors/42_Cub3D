/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:30:28 by aatbir            #+#    #+#             */
/*   Updated: 2024/04/22 15:56:17 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	s = malloc(((ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1)
			* sizeof(char));
	if (!s || !s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}
