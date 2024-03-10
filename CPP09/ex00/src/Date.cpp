/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/10 17:56:02 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/Date.hpp"

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
	std::string aux, aux1;
   	std::stringstream ss;
	const char *t = " /t";

	aux = str;
	aux.erase(0, aux.find_first_not_of(t));
	aux.erase(aux.find_last_not_of(t) + 1, aux.size());
	if (!checkFormatDate (aux))
		throw std::runtime_error("Incorrect date format.");
	aux1 = aux.substr(8, 2);
	ss << aux1;
	ss >> _day;
	ss.str("");
	ss.clear();
	aux1 = aux.substr(5, 2);
	ss << aux1;
	ss >> _month;
	ss.str("");
	ss.clear();
	aux1 = aux.substr(0, 4);
	ss << aux1;
	ss >> _year;
	if (!checkdate(_month, _day, _year))
	{
		std::cout << RED << "<" << aux << ">" << RESET;
		throw std::runtime_error("Incorrect calendar date.");
	}

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
