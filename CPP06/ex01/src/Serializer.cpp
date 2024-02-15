/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:37:07 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/14 22:15:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/Serializer.hpp"



Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer &Serializer::operator=(Serializer const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
