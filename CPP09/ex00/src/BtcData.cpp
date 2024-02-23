
#include "../inc/BtcData.hpp"

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


BtcData::BtcData(){}

BtcData::BtcData(std::string const &str, char const &c)
{
	_delimiter = c;
	_filename = str;
	if (!this->readFile())
		throw("File can't be readed");
}

BtcData::BtcData(BtcData const &rhs)
{
	*this = rhs;
}

BtcData &BtcData::operator=(BtcData const &rhs)
{
	this->_filename = rhs.getFileName();
	this->_delimiter = getDelimiter();
	this->_vec_data = rhs._vec_data;

	return (*this);
}

BtcData::~BtcData(){}

std::string BtcData::getDate(size_t const &i)
{
	return (_vec_data.at(i).op_date.getDate());
}

float BtcData::getVal(size_t const &i)
{
	return (_vec_data[i].ammount);
}

bool BtcData::readFile()
{
	std::ifstream fData;
	std::string line;
	std::string aux;
	t_btc       toadd;

	fData.open(_filename, std::ios::in);
	if (!fData)
	{
		std::cout << "File Data.csv couldn't be opened." << std::endl;
		return false;
	}

	std::getline(fData, line);
	std::cout << line << std::endl;
	while (std::getline(fData, line))
	{
		std::cout << line << std::endl;
		aux = line.substr(0,10);
		std::cout << "paso1 " << aux << std::endl;
		toadd.op_date.putDate(aux);
		std::cout << "paso2 " << std::endl;
		aux = line.substr(11,aux.size() - 11);
		std::cout << "paso3 " << std::endl;
		toadd.ammount = getValue(aux);
		std::cout << "paso " << toadd.op_date.getDate() << "|" <<toadd.ammount << std::endl;
		_vec_data.push_back(toadd);
	}
	fData.close();
	return true;
}

void BtcData::setDelimiter(char const& c)
{
	_delimiter = c;
}

char BtcData::getDelimiter()
{
	return (_delimiter);
} 

void BtcData::setFile(std::string const &str)
{
	_filename = str;
}

std::string BtcData::getFileName() const 
{
	return (_filename);
}

float BtcData::find_acc_note(t_btc const &d)
{
	std::vector<t_btc>::iterator start = _vec_data.begin();
	std::vector<t_btc>::iterator end = _vec_data.end();

	while (start!= end) {
		if (start->op_date.getDay() == d.op_date.getDay()) return start->ammount;
		++start;
	}
	return -1;
}

std::vector<t_btc>::iterator BtcData::getBegin()
{
	return (_vec_data.begin());
}

std::vector<t_btc>::iterator BtcData::getEnd()
{
	return (_vec_data.end());
}
