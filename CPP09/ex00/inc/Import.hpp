/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Import.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:30:36 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/14 09:47:51 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORT_HPP
#define IMPORT_HPP
#include <iostream>
#include <list>
#include <fstream>
#include <limits>
#include "../inc/Date.hpp"
#include "../inc/colors.h"
#include "../inc/utils.hpp"
#include "../inc/BitcoinExchange.hpp"

typedef struct s_data
{
	std::string date;
	float		ammount;
} t_data;

class ImportData
{
private:
	std::list<t_data> _list_data;
	char _delimiter;
	std::string _filename;

public:
	ImportData();
	ImportData(std::string const &, char const &);
	ImportData(ImportData const &);
	ImportData &operator=(ImportData const &);
	~ImportData();
	std::string getDate(size_t &);
	float getVal(size_t &);
	std::string getDate(std::list<t_data>::iterator &);
	float getVal(std::list<t_data>::iterator &);
	bool readFile();
	void setDelimiter(char const &);
	char getDelimiter();
	void setFile(std::string const &);
	std::string getFileName() const;
	std::list<t_data>::iterator getBegin();
	std::list<t_data>::iterator getEnd();
	void printList(BitcoinExchange &);
};

#endif
