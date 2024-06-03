/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:08:21 by aatbir            #+#    #+#             */
/*   Updated: 2022/11/03 21:56:44 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nbrlen(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		j;
	long int	x;

	x = n;
	if (x == 0)
		return (ft_strdup("0"));
	j = nbrlen(x);
	s = (char *)malloc(sizeof(char) * (j + 1));
	if (!s)
		return (NULL);
	s[j] = '\0';
	if (x < 0)
	{
		s[0] = '-';
		x *= -1;
	}
	while (j-- > 0 && x != 0)
	{
		s[j] = (x % 10) + 48;
		x /= 10;
	}
	return (s);
}
