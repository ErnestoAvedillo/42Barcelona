#ifndef BTCDATA_HPP
#define BTCDATA_HPP
#include <iostream>
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

class BtcData
{
	private:
		std::vector <t_btc> _vec_data;
		char _delimiter;
		std::string _filename;
	public:
		BtcData();
		BtcData(std::string const &, char const &);
		BtcData(BtcData const &);
		BtcData &operator=(BtcData const &);
		~BtcData();
		Date getDate(size_t const &);
		float getVal(size_t const &);
		bool readFile();
		void setDelimiter(char const&);
		char getDelimiter();
		void setFile(std::string const &);
		std::string getFileName() const;
		float find_acc_note(Date const &);
		std::vector<t_btc>::iterator getBegin();
		std::vector<t_btc>::iterator getEnd();
};
#endif
