/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:14:47 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 20:03:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (s1[counter] != '\0' && counter < n)
	{
		if (s1[counter] != s2[counter])
			return (s1[counter] - s2[counter]);
		counter++;
	}
	return (0);
}
