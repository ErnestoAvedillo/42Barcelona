/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Import.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:36:47 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/14 10:16:53 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Import.hpp"

ImportData::ImportData(){}

ImportData::ImportData(std::string const &str, char const &c)
{
	_delimiter = c;
	_filename = str;
	if (!this->readFile())
		throw("File can't be readed");
}

ImportData::ImportData(ImportData const &rhs)
{
	*this = rhs;
}

ImportData &ImportData::operator=(ImportData const &rhs)
{
	this->_filename = rhs.getFileName();
	this->_delimiter = getDelimiter();
	this->_list_data = rhs._list_data;

	return (*this);
}

ImportData::~ImportData(){}

std::string ImportData::getDate(size_t &n)
{
	std::list<t_data>::iterator it = _list_data.begin();
	for (size_t i = 0; i < n; i++)
		it++;
	return (it->date);
}

float ImportData::getVal(size_t &n)
{

	std::list<t_data>::iterator it = _list_data.begin();
	for (size_t i = 0; i < n; i++)
		it++;
	return (it->ammount);
}

std::string ImportData::getDate(std::list<t_data>::iterator &it)
{
	return (it->date);
}

float ImportData::getVal(std::list<t_data>::iterator &it)
{
	return (it->ammount);
}

bool ImportData::readFile()
{
	std::ifstream fData;
	std::string line;
	t_data acc_note;
	std::string aux;

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
		acc_note.ammount = getValue(aux);
		acc_note.date = line.substr(0,line.find(_delimiter,0));
		_list_data.push_back(acc_note);
	}
	fData.close();
	return true;
}

void ImportData::setDelimiter(char const& c)
{
	_delimiter = c;
}

char ImportData::getDelimiter()
{
	return (_delimiter);
} 

void ImportData::setFile(std::string const &str)
{
	_filename = str;
}

std::string ImportData::getFileName() const 
{
	return (_filename);
}

std::list<t_data>::iterator ImportData::getBegin()
{
	return (_list_data.begin());
}

std::list<t_data>::iterator ImportData::getEnd()
{
	return (_list_data.end());
}

void ImportData::printList(BitcoinExchange &btc)
{
	std::map<std::string, float>::iterator acc_note;
	Date la_fecha;

	std::cout << GREEN "Listado de valores del fichero: " << _filename << RESET << std::endl;
	for (std::list<t_data>::iterator x = _list_data.begin(); x != _list_data.end(); x++)
	{
		try
		{
			la_fecha.putDate(this->getDate(x));
			acc_note = btc.find_acc_note(x->date);
			if (x->ammount == std::numeric_limits<float>::quiet_NaN() || x->ammount > 1000 || x->ammount < 0)
			{
				std::cout << "Date: " << la_fecha << "-->" RED << std::setfill(' ') << std::setw(5) << x->ammount;
				std::cout << " Is an Incorrect quantity " RESET << std::endl;
			}
			else
			{
				std::cout << "Date: " << la_fecha << " quantity: " << std::setfill(' ') << std::setw(5) << x->ammount;
				std::cout << " value -->" << std::setfill(' ') << std::setw(11) << x->ammount * acc_note->second;
				std::cout << " (Value " << std::setfill(' ') << std::setw(7) << acc_note->second;
				std::cout << " from date: " << acc_note->first << ")" << std::endl;
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}
