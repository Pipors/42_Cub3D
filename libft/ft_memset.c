/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:34:22 by aatbir            #+#    #+#             */
/*   Updated: 2022/10/05 22:28:45 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	pos;

	pos = 0;
	while (pos < len)
	{
		((unsigned char *)str)[pos] = (unsigned char)c;
		pos++;
	}
	return (str);
}
