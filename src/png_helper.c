/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:41:06 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 16:47:12 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

const char	*valid_first(t_info *info, char *filename)
{
	const char		*first;
	int				fd;
	int				pos;

	info = get_info(info, filename);
	free(info->second_info);
	free(info->third_info);
	free(info->fourth_info);
	free(info->second_color);
	free(info->first_color);
	first = (const char *)ft_half_strtrim(info->first_info, "NEWSOA \t");
	pos = ft_strlen((char *)first);
	if ((first[pos - 1] != 'g' && first[pos - 1] != 'G')
		|| (first[pos - 2] != 'n' && first[pos - 2] != 'N')
		|| (first[pos - 3] != 'p' && first[pos - 3] != 'p')
		|| first[pos - 4] != '.')
		throw_err_2("Error\nTexture must be in .png extension\n");
	fd = open(first, O_RDONLY);
	if (fd == -1 || !info || !first)
		return (free(info), NULL);
	close(fd);
	free(info->first_info);
	return (free(info), first);
}

const char	*valid_second(t_info *info, char *filename)
{
	const char		*second;
	int				fd;
	int				pos;

	info = get_info(info, filename);
	free(info->first_info);
	free(info->third_info);
	free(info->fourth_info);
	free(info->second_color);
	free(info->first_color);
	second = (const char *)ft_half_strtrim(info->second_info, "NEWSOA \t");
	pos = ft_strlen((char *)second);
	if ((second[pos - 1] != 'g' && second[pos - 1] != 'G')
		|| (second[pos - 2] != 'n' && second[pos - 2] != 'N')
		|| (second[pos - 3] != 'p' && second[pos - 3] != 'p')
		|| second[pos - 4] != '.')
		throw_err_2("Error\nTexture must be in .png extension\n");
	fd = open(second, O_RDONLY);
	if (fd == -1 || !info || !second)
		return (free(info), NULL);
	close(fd);
	free(info->second_info);
	return (free(info), second);
}

const char	*valid_third(t_info *info, char *filename)
{
	const char		*third;
	int				fd;
	int				pos;

	info = get_info(info, filename);
	free(info->first_info);
	free(info->second_info);
	free(info->fourth_info);
	free(info->second_color);
	free(info->first_color);
	third = (const char *)ft_half_strtrim(info->third_info, "NEWSOA \t");
	pos = ft_strlen((char *)third);
	if ((third[pos - 1] != 'g' && third[pos - 1] != 'G')
		|| (third[pos - 2] != 'n' && third[pos - 2] != 'N')
		|| (third[pos - 3] != 'p' && third[pos - 3] != 'p')
		|| third[pos - 4] != '.')
		throw_err_2("Error\nTexture must be in .png extension\n");
	fd = open(third, O_RDONLY);
	if (fd == -1 || !info || !third)
		return (free(info), NULL);
	close(fd);
	free(info->third_info);
	return (free(info), third);
}

const char	*valid_fourth(t_info *info, char *filename)
{
	const char		*fourth;
	int				fd;
	int				pos;

	info = get_info(info, filename);
	free(info->first_info);
	free(info->second_info);
	free(info->third_info);
	free(info->second_color);
	free(info->first_color);
	fourth = (const char *)ft_half_strtrim(info->fourth_info, "NEWSOA \t");
	pos = ft_strlen((char *)fourth);
	if ((fourth[pos - 1] != 'g' && fourth[pos - 1] != 'G')
		|| (fourth[pos - 2] != 'n' && fourth[pos - 2] != 'N')
		|| (fourth[pos - 3] != 'p' && fourth[pos - 3] != 'p')
		|| fourth[pos - 4] != '.')
		throw_err_2("Error\nTexture must be in .png extension\n");
	fd = open(fourth, O_RDONLY);
	if (fd == -1 || !info || !fourth)
		return (free(info), NULL);
	close(fd);
	free(info->fourth_info);
	return (free(info), fourth);
}
