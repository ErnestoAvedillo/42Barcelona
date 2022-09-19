/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/18 19:18:35 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}			t_list;

typedef struct s_split_next
{
	
}			t_split_next;

int 	ft_isalpha(int c);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int 	ft_isprint(int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
size_t 	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);;
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);

#endif
