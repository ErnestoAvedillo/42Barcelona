/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:33:51 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/25 18:34:06 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<sys/types.h>
# include<unistd.h>
# include<stddef.h>
# include<stdio.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line_bonus(int fd);
int		my_strlen(char *str);
int		my_strchr(char *str, char c);
char	*my_joinstr(char *dst, char *src);
char	*my_substr(char *str, int start, int len);
#endif
