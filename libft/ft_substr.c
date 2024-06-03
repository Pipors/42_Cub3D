/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:57:27 by aatbir            #+#    #+#             */
/*   Updated: 2024/04/25 17:58:11 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
