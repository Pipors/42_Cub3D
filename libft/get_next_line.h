/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:22:12 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/05/20 12:22:19 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen_gnl(char *str);
char	*ft_strjjoin(char *s1, char *s2);
char	*ft_strchhr( char *s, int c);
char	*get_next_line(int fd);
int		new_line(char *str);
char	*read_fd(int fd, char *line);
char	*ft_before_line(char *line);
char	*ft_after_line(char *line);

#endif