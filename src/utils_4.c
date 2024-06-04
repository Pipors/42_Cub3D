/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:45:34 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 18:54:31 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	check_first_path(t_info *info, char **str, int i)
{
	if (info->first_info != NULL)
		throw_err_2("error: duplicate\n");
	else
		info->first_info = ft_strdup(str[i]);
}

void	check_second_path(t_info *info, char **str, int i)
{
	if (info->second_info != NULL)
		throw_err_2("error: duplicate\n");
	else
		info->second_info = ft_strdup(str[i]);
}

void	check_third_path(t_info *info, char **str, int i)
{
	if (info->third_info != NULL)
		throw_err_2("error: duplicate\n");
	else
		info->third_info = ft_strdup(str[i]);
}

void	check_fourth_path(t_info *info, char **str, int i)
{
	if (info->fourth_info != NULL)
		throw_err_2("error: duplicate\n");
	else
		info->fourth_info = ft_strdup(str[i]);
}
