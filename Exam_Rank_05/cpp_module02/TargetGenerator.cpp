/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/19 21:59:49 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp" 

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget*){}
void TargetGenerator::forgetTargetType(std::string const &){}
ATarget* TargetGenerator::createTarget(std::string const &){}
