/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:33:58 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/06 16:10:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <iostream>
#include <cstdint>

typedef struct s_Data
{
	char	c;
	int		i;
	void	*ptr;
} Data;

class Serializer
{
private:
	/* data */
public:
	Serializer(/* args */);
	~Serializer();
	Serializer &operator=(Serializer const &);
	uintptr_t serialize(Data *ptr);
	Data* deserialize(uintptr_t raw);
};
#endif