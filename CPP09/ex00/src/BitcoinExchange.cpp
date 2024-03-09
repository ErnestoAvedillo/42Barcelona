/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:20 by marvin            #+#    #+#             */
/*   Updated: 2024/03/06 19:16:46 by eavedill         ###   ########.fr       */
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
	this->_vec_data = rhs._vec_data;

	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

Date BitcoinExchange::getDate(size_t const &n)
{
	std::list<t_btc>::iterator  it = _vec_data.begin();
	for (size_t i = 0; i < n; i++)
		it++;
	return (it->op_date);
}

float BitcoinExchange::getVal(size_t const &n)
{
	std::list<t_btc>::iterator  it = _vec_data.begin();
	for (size_t i = 0; i < n; i++)
		it++;
	return (it->ammount);
}

bool BitcoinExchange::readFile()
{
	std::ifstream fData;
	std::string line;
	std::string aux;
	t_btc       toadd;

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
		toadd.op_date.putDate(aux);
		aux = line.substr(11,aux.size() - 11);
		toadd.ammount = getValue(aux);
		_vec_data.push_back(toadd);
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

float BitcoinExchange::find_acc_note(Date const &d)
{
	std::list<t_btc>::iterator start = _vec_data.begin();
	std::list<t_btc>::iterator end = _vec_data.end();
	if (!checkdate(d.getMonth(),d.getDay(),d.getYear()))
		throw std::runtime_error("Incorrect date");
	while (start!= end) {
		if (start->op_date >= d) 
			return start->ammount;
		++start;
	}
	end--;
	return  end->ammount;
}

std::list<t_btc>::iterator BitcoinExchange::getBegin()
{
	return (_vec_data.begin());
}

std::list<t_btc>::iterator BitcoinExchange::getEnd()
{
	return (_vec_data.end());
}

void BitcoinExchange::printVector()
{
	for(size_t i = 0; i < _vec_data.size();  i++)
	{
		Date cur_date = this->getDate(i);
		std::cout << cur_date.getYear() << "-";
	    std::cout << std::setfill('0') << std::setw(2) << cur_date.getMonth() << "-";
	    std::cout << std::setfill('0') << std::setw(2) << cur_date.getDay();
		std::cout << "-->" << this->getVal(i) << std::endl;
	}

}
