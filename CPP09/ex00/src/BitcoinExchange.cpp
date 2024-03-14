/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:20 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 20:13:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/BitcoinExchange.hpp"

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
		if (line.find(_delimiter,0) != std::string::npos)
			aux = line.substr(line.find(_delimiter,0) + 1, line.size() - line.find(_delimiter,0));
		else
		{
			std::cout << YELLOW << _filename << RESET << ": incorrect syntaxis line  ==>" << RED << line << RESET << std::endl;
		}
		ammount = getValue(aux);
		aux = line.substr(0,line.find(_delimiter,0));
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

std::map<std::string, float>::iterator BitcoinExchange::find_acc_note(std::string const &d)
{
	std::map<std::string, float>::iterator it = _map_data.lower_bound(d);
	if (it != _map_data.begin())
	{
		if (it == _map_data.end()) 
			it--;
		else if (it->first != d)
			it--;
	}
	return it;
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
	for (std::map<std::string, float>::const_iterator x = _map_data.begin(); x != _map_data.end(); x++)
	{
		std::cout << x->first << "---" << x->second << std::endl;
	}

}
