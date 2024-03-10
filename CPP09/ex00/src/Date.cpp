/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/09 20:08:44 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/Date.hpp"

static int count_chr(std::string str, char c)
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

static bool checkFormatDate(std::string const &str)
{
	if (str.size() != 10)
	{
		std::cerr << "longitud errónea" << str << std::endl;
		return false;
	}
	if (str.find_first_not_of("0123456789-") != std::string::npos)
	{
		std::cerr << "datos" << std::endl;
		return false;
	}
	if (count_chr(str, '-') != 2)
	{
		std::cerr << "Guion" << std::endl;
		return false;
	}
	if (str.at(4) != '-' && str.at(7) != '-')
	{
		std::cerr << "posicion guiones" << std::endl;
		return false;
	}
	return true;
}

Date::Date()
{
	_day = 00;
	_month = 00;
	_year = 00;
}

Date::Date(std::string const & str)
{
	this->putDate(str);
}

Date::Date(Date const &rhs)
{
	*this = rhs;
}

Date &Date::operator=(Date const &rhs)
{
	_day = rhs.getDay();
	_month = rhs.getMonth();
	_year = rhs.getYear();
	return *this;
}

bool Date::operator==(const Date &rhs) const
{
	if (_year==rhs.getYear() && _month == rhs.getMonth() && _day == rhs.getDay())
		return true;
	return false;
}
bool Date::operator>(const Date &rhs) const
{
	if(_year <= rhs.getYear())
		return false;
	else if (_year == rhs.getYear() && _month <= getMonth())
		return false;
	else if (_day <= rhs.getDay() && _year == rhs.getYear() && _month == getMonth())
		return false;
	return true;
}
bool Date::operator<(const Date &rhs) const
{
	if(_year >= rhs.getYear())
		return (false);
	else if (_year == rhs.getYear() && _month >= rhs.getMonth())
		return false;
	else if (_day >= rhs.getDay() && _year == rhs.getYear() && _month < rhs.getMonth())
		return false;
	return true;
}
bool Date::operator<=(const Date &rhs) const
{
	if(_year > rhs.getYear())
		return false;
	else if (_year == rhs.getYear() && _month > rhs.getMonth())
		return false;
	else if (_day < rhs.getDay() && _year == rhs.getYear() && _month == rhs.getMonth())
		return false;
	return true;
}
bool Date::operator>=(const Date &rhs) const
{
	if(_year<rhs.getYear())
		return false;
	else if (_year == rhs.getYear() && _month < rhs.getMonth())
		return false;
	else if (_day < rhs.getDay() && _year == rhs.getYear() && _month < rhs.getMonth())
		return false;
	return true;
}


Date::~Date(){}

void Date::putDate(std::string const &str)
{
	std::string aux;
   	std::stringstream ss;
	
	if (!checkFormatDate (str))
		throw std::runtime_error("Incorrect date fromat.");
	aux = str.substr(8, 2);
	ss << aux;
	ss >> _day;
	ss.str("");
	ss.clear();
	aux = str.substr(5, 2);
	ss << aux;
	ss >> _month;
	ss.str("");
	ss.clear();
	aux = str.substr(0, 4);
	ss << aux;
	ss >> _year;
}

std::string Date::getDate()
{
	std::string str, str1;
	std::stringstream aux;
	aux << _year;
	aux >> str;
	aux.str("");
	aux.clear();
	aux << std::setfill('0') << std::setw(2) << _month;
	aux >> str1;
	str = str + '-' + str1;
	aux.str("");
	aux.clear();
	aux << std::setfill('0') << std::setw(2) << _day;
	aux >> str1;
	str = str + '-' + str1;
	return str;
}

int Date::getDay() const
{
	return(_day);
}
int Date::getMonth() const
{
	return (_month);
}
int Date::getYear() const
{
	return _year;
}

std::ostream &operator<<(std::ostream &ost, Date const &d)
{
    ost << d.getYear() << "-";
    ost << std::setfill('0') << std::setw(2) << d.getMonth() << "-";
    ost << std::setfill('0') << std::setw(2) << d.getDay();
    return ost;
}
