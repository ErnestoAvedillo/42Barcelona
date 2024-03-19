/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:32:55 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp" 


Dummy::Dummy():ATarget("Target Practice Dummy"){}
Dummy::~Dummy()
{}

ATarget *Dummy::clone() const
{
	return (new Dummy()); 
}
