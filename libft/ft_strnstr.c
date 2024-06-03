/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:06:35 by aatbir            #+#    #+#             */
/*   Updated: 2022/11/14 22:13:51 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	n;

	if (*s2 == '\0')
		return ((char *)s1);
	if (len == 0)
		return (0);
	while (*s1 == '\0' || len == 0)
		return (0);
	n = ft_strlen((char *)s2);
	while (*s1 != '\0' && len-- >= n)
	{
		if (*s1 == *s2 && (ft_memcmp(s1, s2, n) == 0))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
