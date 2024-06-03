/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:13:15 by aatbir            #+#    #+#             */
/*   Updated: 2024/05/20 12:19:59 by hbelhadj         ###   ########.fr       */
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
