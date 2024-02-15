/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:33:58 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/14 22:13:41 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <iostream>
//#include <cstdint>

typedef struct s_Data
{
	char	c;
	int		i;
	void	*ptr;
} Data;

class Serializer
{
private:
	Serializer(/* args */);
	~Serializer();
	Serializer &operator=(Serializer const &);
public:
	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif
