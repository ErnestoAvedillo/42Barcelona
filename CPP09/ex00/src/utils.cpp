/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:09:52 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/14 10:13:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

bool checkdate(int m, int d, int y)
{
  if (! (1582<= y )  )
	 return false;
  if (! (1<= m && m<=12) )
	 return false;
  if (! (1<= d && d<=31) )
	 return false;
  if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
	 return false;
  if ( (d==30) && (m==2) )
	 return false;
  if ( (m==2) && (d==29) && (y%4!=0) )
	 return false;
  if ( (m==2) && (d==29) && (y%400==0) )
	 return true;
  if ( (m==2) && (d==29) && (y%100==0) )
	 return false;
  if ( (m==2) && (d==29) && (y%4==0)  )
	 return true;
 
  return true;
}


int count_chr(std::string str, char c)
{
	int out;

	out = 0;
	for (size_t i = 0; i < str.size(); i++)
		if(str[i] == c)
			out++;
	return out;
}

int extractDay(std::string const & str)
{
	int i;
	std::string aux;
   	std::stringstream ss;
	
	aux = str.substr(9, 2);
	ss << aux;
	ss >> i;
	return i;
}
int extractMonth(std::string const & str)
{
	int i;
	std::string aux;
   	std::stringstream ss;
	
	aux = str.substr(5, 2);
	ss << aux;
	ss >> i;
	return i;
}
int extractYear(std::string const & str)
{
	int i;
	std::string aux;
   	std::stringstream ss;

	aux = str.substr(0, 4);
	ss << aux;
	ss >> i;
	return i;
}

bool checkFormatDate(std::string const &str)
{
	if (str.size() != 10)
	{
		std::cerr << "Incorrect length " << RED << str << RESET << ". ";
		return false;
	}
	if (str.find_first_not_of("0123456789-") != std::string::npos)
	{
		std::cerr << "Incorrect Data " << RED << str << RESET << ". ";
		return false;
	}
	if (count_chr(str, '-') != 2)
	{
		std::cerr << "Incorrect format Date " << RED << str << RESET << ". ";
		return false;
	}
	if (str.at(4) != '-' && str.at(7) != '-')
	{
		std::cerr << "Incorrect format Date " << RED << str << RESET << ". ";
		return false;
	}
	return true;
}

std::string all_trim(std::string str)
{
	std::string out;
	const char *t = " /t";

	out = str;
	out.erase(0, out.find_first_not_of(t));
	out.erase(out.find_last_not_of(t) + 1, out.size());
	return out;
}

float getValue(std::string str)
{
	float out = 0;

	std::stringstream ss;
	out = std::numeric_limits<float>::quiet_NaN();
	str = all_trim(str);
	if (str.empty())
		return out;
	if (str.find_first_not_of("-0123456789.") != std::string::npos ||
		count_chr(str, '.') > 1 || count_chr(str, '-') > 1)
		return out;
	if (count_chr(str, '-') == 1 and str.at(0) != '-')
		return out;
	ss << str;
	ss >> out;
	return out; 
}
