/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:20 by marvin            #+#    #+#             */
/*   Updated: 2024/03/09 14:21:05 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/BitcoinExchange.hpp"

static int count_chr(std::string str, char c)
{
	int out;

	out = 0;
	for (size_t i = 0; i < str.size(); i++)
		if(str[i] == c)
			out++;
	return out;
}

static float getValue(std::string str)
{
	float out = 0;

	std::stringstream ss;
	out = std::numeric_limits<float>::quiet_NaN();
	if (str.empty())
		return out;
	if (str.find_first_not_of("0123456789.") != std::string::npos || \
		count_chr(str, '.') > 1 )
		return out;
	ss << str;
	ss >> out;
	return out; 
}


BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string const &str, char const &c)
{
	_delimiter = c;
	_filename = str;
	if (!this->readFile())
		throw("File can't be readed");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs)
{
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	this->_filename = rhs.getFileName();
	this->_delimiter = getDelimiter();
	this->_map_data = rhs._map_data;

	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::getDate(size_t &n)
{
	std::map<std::string, float>::iterator it = _map_data.begin();
	for (size_t i = 0; i < n; i++)
		it++;
	return (it->first);
}

float BitcoinExchange::getVal(size_t &n)
{
	
	std::map<std::string, float>::iterator it = _map_data.begin();
	for (size_t i = 0; i < n; i++)
		it++;
	return (it->second);
}

std::string BitcoinExchange::getDate(std::map<std::string, float>::iterator &it)
{
	return (it->first);
}

float BitcoinExchange::getVal(std::map<std::string, float>::iterator &it)
{
	return (it->second);
}

bool BitcoinExchange::readFile()
{
	std::ifstream fData;
	std::string line;
	std::string aux;
	float ammount;

	fData.open(_filename.c_str(), std::ios::in);
	if (!fData)
	{
		std::cout << "File Data.csv couldn't be opened." << std::endl;
		return false;
	}

	std::getline(fData, line);
	while (std::getline(fData, line))
	{
		aux = line.substr(0,10);
		aux = line.substr(11,aux.size() - 11);
		ammount = getValue(aux);
		_map_data[aux] = ammount;
	}
	fData.close();
	return true;
}

void BitcoinExchange::setDelimiter(char const& c)
{
	_delimiter = c;
}

char BitcoinExchange::getDelimiter()
{
	return (_delimiter);
} 

void BitcoinExchange::setFile(std::string const &str)
{
	_filename = str;
}

std::string BitcoinExchange::getFileName() const 
{
	return (_filename);
}

float BitcoinExchange::find_acc_note(std::string const &d)
{
	std::map<std::string, float>::iterator it = _map_data.lower_bound(d);
	return it->second;
}

std::map<std::string, float>::iterator BitcoinExchange::getBegin()
{
	return (_map_data.begin());
}

std::map<std::string, float>::iterator BitcoinExchange::getEnd()
{
	return (_map_data.end());
}

void BitcoinExchange::printVector()
{
	for (std::map<std::string, float>::iterator x = _map_data.begin(); x != _map_data.end(); x++)
	{
		std::cout << x->first << x->second << std::endl;
	}

}
