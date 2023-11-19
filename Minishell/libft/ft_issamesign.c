/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issamesign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:10:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/18 17:33:46 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_issamesign(int a, int b)
{
	if (ft_ispositive(a) && ft_ispositive(b))
		return (1);
	if (!ft_ispositive(a) && !ft_ispositive(b))
		return (1);
	return (0);
}
