/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:03:53 by aatbir            #+#    #+#             */
/*   Updated: 2022/11/17 20:40:41 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += ((*(str + i) - '0'));
		str++;
	}
	return (result * sign);
}
