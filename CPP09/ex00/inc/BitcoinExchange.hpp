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
#include <vector>
#include <fstream>
#include <limits>
#include "../inc/Date.hpp"

bool checkdate(int m, int d, int y);

typedef struct s_btc
{
	Date    op_date;
	float   ammount;
}   t_btc;

class BitcoinExchange
{
	private:
		std::list <t_btc> _vec_data;
		char _delimiter;
		std::string _filename;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &, char const &);
		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange &operator=(BitcoinExchange const &);
		~BitcoinExchange();
		Date getDate(size_t const &);
		float getVal(size_t const &);
		bool readFile();
		void setDelimiter(char const&);
		char getDelimiter();
		void setFile(std::string const &);
		std::string getFileName() const;
		float find_acc_note(Date const &);
		std::list<t_btc>::iterator getBegin();
		std::list<t_btc>::iterator getEnd();
		void printVector();
};

#endif
