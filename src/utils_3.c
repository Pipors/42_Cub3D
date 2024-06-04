/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:45:22 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 18:54:23 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	check_first_color(t_info *info, char **str, int i)
{
	if (info->first_color != NULL)
	{
		free(str[i]);
		throw_err_2("error: duplicate\n");
	}
	else
		info->first_color = ft_strdup(str[i]);
}

void	check_second_color(t_info *info, char **str, int i)
{
	if (info->second_color != NULL)
		throw_err_2("error: duplicate\n");
	else
		info->second_color = ft_strdup(str[i]);
}
