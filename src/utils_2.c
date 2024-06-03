/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:17:27 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 16:55:31 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int32_t ft_pixel(int r, int g, int b, int alpha)
{
    return (alpha << 24) | (r << 16) | (g << 8) | b;
}

int32_t reverseRGB(char* input)
{
    // Check for NULL input
    if (input == NULL)
        return -1; // Return an error code

    // Find the positions of the commas
    const char* comma1 = strchr(input, ',');
    if (comma1 == NULL)
        return -1; // Return an error code if the input format is incorrect

    const char* comma2 = strchr(comma1 + 1, ',');
    if (comma2 == NULL)
        return -1; // Return an error code if the input format is incorrect

    // Extract the RGB values
    int r = atoi(input);
    int g = atoi(comma1 + 1);
    int b = atoi(comma2 + 1);

    // Reverse the RGB values
    int reversedR = b;
    int reversedG = g;
    int reversedB = r;

    // Assuming alpha value is 255 (fully opaque)
    int alpha = 255;

    // Pack the reversed RGB values with the alpha value into a 32-bit integer
    return ft_pixel(reversedR, reversedG, reversedB, alpha);
}
/* TAKING ONLY THE FIRST WORD FROM A GIVEN LINE, WHICH IS IN OUR CASE 
"NO" "SO" "WE" "EA" "F" "C" */
char	*take_first_string(char *line)
{
	char	*first_part; 
	int		i;
	int		j;

	i = 0;
	j = 0;
	first_part = malloc(2);
	if (!line || !first_part)
		return (NULL);
	if (line[i] != '\0')
	{
		while (line[i] != 32 && line[i] != '\t' && j < 2)
			first_part[j++] = line[i++];
		first_part[j] = '\0';
	}
	return (first_part);
}

/* CHECKING IF THE LEN OF THE FIRST WORD MATCHES THE LEN OF THE TARGET WHICH
IS ONE OF THESE WORDS => "NO" "SO" "WE" "EA" "F" "C" */
char	*start_with(char *first_word, char *target, size_t size)
{
	char	*tmp;

	tmp = take_first_string(first_word);
	if (ft_strncmp(tmp, target, size) == 0)
		return (free(tmp), first_word);
	else
		return (free(tmp), NULL);
}

/* FILLING THE STRUCT WITH INFO WHEN DIRECTIONS ARE WRITTEN IN CORRECT WAY
AFTER CHECKING IF THE INFO IN STR MATCHES THE THE TARGET WHILE
RESPECTING ITS LEN */
t_info	*get_info(t_info *info, char *filename)
{
	char	**str;
	int		i;

	i = 0;
	info = ft_calloc(sizeof(t_info), 1);
	// printf("s->---------%s\n",info->first_info);
	str = splimed_key_value_6(filename);
	while (str[i] != NULL)
	{
		if (start_with(str[i], "NO", 2) != NULL)
		{
			if(info->first_info != NULL)
			{
				throw_err_2("error: duplicate\n");
				exit(1);
			}
			else
				info->first_info = ft_strdup(str[i]);
		}
		else if (start_with(str[i], "SO", 2) != NULL)
		{
			if(info->second_info != NULL)
			{
				throw_err_2("error: duplicate\n");
				exit(1);
			}
			else
				info->second_info = ft_strdup(str[i]);
		}
		else if (start_with(str[i], "WE", 2) != NULL)
		{
			if(info->third_info != NULL)
			{
				throw_err_2("error: duplicate\n");
				exit(1);
			}
			else
				info->third_info = ft_strdup(str[i]);
		}
		else if (start_with(str[i], "EA", 2) != NULL)
		{
			if(info->fourth_info != NULL)
			{
				throw_err_2("error: duplicate\n");
				exit(1);
			}
			else
				info->fourth_info = ft_strdup(str[i]);
		}
		else if (start_with(str[i], "F",  1) != NULL)
		{
			if(info->first_color != NULL)
			{
				throw_err_2("error: duplicate\n");
				exit(1);
			}
			else
				info->first_color = ft_strdup(str[i]);
		}
		else if (start_with(str[i], "C", 1) != NULL)
		{
			if(info->second_color != NULL)
			{
				throw_err_2("error: duplicate\n");
				exit(1);
			}
			else
			{
				info->second_color = ft_strdup(str[i]);
				// printf("second_color===%s\n", info->second_color);
			}
		}
		else
			throw_err_2("Wrong Identifier\n");
		i++;
	}
	return (arr_free(str), info);
}

/* REGROUP INFO IN THE STRUCT IN **CHAR TO FACILITATE DATA ACCESSING */
char	**store_get_info_in_array(t_info *info, char *filename)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * 7);
	info->first_info = 0;
	info->second_info = 0;
	info->third_info = 0;
	info->fourth_info = 0;
	info->first_color = 0;
	info->second_color = 0;
	info = get_info(info, filename);
	if (!str || !info)
		return (NULL);
	str[0] = ft_strdup(info->first_info);
	str[1] = ft_strdup(info->second_info);
	str[2] = ft_strdup(info->third_info);
	str[3] = ft_strdup(info->fourth_info);
	str[4] = ft_strdup(info->first_color);
	str[5] = ft_strdup(info->second_color);
	str[6] = NULL;
	free(info);
	return (str);
}
