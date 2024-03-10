/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:41 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 07:31:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <fstream>
#include <limits>
#include "../inc/Date.hpp"


typedef struct s_btc
{
	Date    op_date;
	float   ammount;
}   t_btc;

class BitcoinExchange
{
	private:
		std::map<std::string,float> _map_data;
		char _delimiter;
		std::string _filename;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &, char const &);
		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange &operator=(BitcoinExchange const &);
		~BitcoinExchange();
		std::string getDate(size_t &);
		float getVal(size_t &);
		std::string getDate(std::map<std::string, float>::iterator &);
		float getVal(std::map<std::string, float>::iterator &);
		bool readFile();
		void setDelimiter(char const&);
		char getDelimiter();
		void setFile(std::string const &);
		std::string getFileName() const;
		float find_acc_note(std::string const &);
		std::map<std::string, float>::iterator getBegin();
		std::map<std::string, float>::iterator getEnd();
		void printVector();
};

#endif
