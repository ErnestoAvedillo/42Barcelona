/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:20:05 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/17 06:23:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		my_strlen(char *str);
int		my_strchr(char *str, char c);
char	*my_joinstr(char *dst, char *src, int lensrc);
char	*my_substr(char *str, int start, int len);
void	free_null(char **ptr);
#endif
