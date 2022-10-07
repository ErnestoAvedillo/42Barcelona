/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:12:12 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 16:13:37 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	intro;

	intro = '\n';
	ft_putstr_fd (s, fd);
	write(fd, &intro, 1);
}
