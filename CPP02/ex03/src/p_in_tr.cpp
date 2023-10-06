/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_in_tr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:45:12 by eavedill          #+#    #+#             */
/*   Updated: 2023/10/06 15:45:28 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/main.h"

bool p_in_tr(Point a, Point b, Point c, Point d)
{
	Fixed V1[] = {b.GetXCoord()- a.GetXCoord(), b.GetYCoord() - a.GetYCoord()};
	Fixed V2[] = {c.GetXCoord()- a.GetXCoord(), c.GetYCoord() - a.GetYCoord()};
	Fixed VP[] = {d.GetXCoord()- a.GetXCoord(), d.GetYCoord() - a.GetYCoord()};
	std::cout << "a " << a << "--" << a.GetXCoord() << " " << a.GetYCoord() << std::endl;
	std::cout << "b " << b << "--" << b.GetXCoord() << " " << b.GetYCoord() << std::endl;
	std::cout << "c " << c << "--" << c.GetXCoord() << " " << c.GetYCoord() << std::endl;
	std::cout << "d " << d << "--" << d.GetXCoord() << " " << d.GetYCoord() << std::endl;
	std::cout << "V1 " << V1[0] << " , " << V1[1] << std::endl;
	std::cout << "V2 " << V2[0] << " , " << V2[1] << std::endl;
	std::cout << "VP " << VP[0] << " , " << VP[1] << std::endl;
	Fixed Pab = V1[0] / V1[1];
	Fixed Pac = V2[0] / V2[1];
	Fixed Pad = VP[0] / VP[1];
	Fixed W2 = Pab * VP[1] * ((Fixed)1 - Pad) / V2[1] / (Pab - Pac);
	Fixed W1 = (VP[1] - W2 * V2[1]) / V1[1];

	std::cout << "Pad " << Pab  << std::endl;
	std::cout << "Pad " << Pac  << std::endl;
	std::cout << "Pad " << Pad  << std::endl;
	std::cout << "Los valores W1 y W2 son respectivamente= " << W1 << " - " << W2 << std::endl;

	if (W1 >= 0 && W2 >= 0 && (W1 + W2 <= 1))
		return true;
	return false; 

}
