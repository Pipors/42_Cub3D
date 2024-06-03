/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:26:30 by aatbir            #+#    #+#             */
/*   Updated: 2024/05/20 11:05:27 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest,  char *src, size_t len)
{
	size_t	i;
	size_t	s;
	size_t	v;

	if (len == 0)
		return (ft_strlen(src));
	else if (len < ft_strlen(dest))
		v = ft_strlen(src) + len;
	else
		v = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	while (dest[i] != '\0')
		i++;
	s = 0;
	while (src[s] != '\0' && i + 1 < len)
	{
		dest[i] = src[s];
		s++;
		i++;
	}
	dest[i] = '\0';
	return (v);
}
