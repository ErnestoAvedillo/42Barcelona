/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:16:28 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 10:18:49 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
