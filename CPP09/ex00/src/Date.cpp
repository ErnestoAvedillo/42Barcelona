#include  "../inc/Date.hpp"

static int count_chr(std::string str, char c)
{
	int out;

	out = 0;
	for (size_t i = 0; i < str.size(); i++)
		if(str[i] == c)
			out++;
	return out;
}

int extractDay(std::string const & str)
{
	int i;
	std::string aux;
   	std::stringstream ss;
	
	aux = str.substr(9, 2);
	ss << aux;
	ss >> i;
	return i;
}
int extractMonth(std::string const & str)
{
	int i;
	std::string aux;
   	std::stringstream ss;
	
	aux = str.substr(5, 2);
	ss << aux;
	ss >> i;
	return i;
}
int extractYear(std::string const & str)
{
	int i;
	std::string aux;
   	std::stringstream ss;

	aux = str.substr(0, 4);
	ss << aux;
	ss >> i;
	return i;
}

bool checkdate(int m, int d, int y)
{
  if (! (1582<= y )  )
	 return false;
  if (! (1<= m && m<=12) )
	 return false;
  if (! (1<= d && d<=31) )
	 return false;
  if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
	 return false;
  if ( (d==30) && (m==2) )
	 return false;
  if ( (m==2) && (d==29) && (y%4!=0) )
	 return false;
  if ( (m==2) && (d==29) && (y%400==0) )
	 return true;
  if ( (m==2) && (d==29) && (y%100==0) )
	 return false;
  if ( (m==2) && (d==29) && (y%4==0)  )
	 return true;
 
  return true;
}

static bool checkFormatDate(std::string const &str)
{
	if (str.size() != 10)
	{
		std::cerr << "longitud" << std::endl;
		return false;
	}
	if (str.find_first_not_of("0123456789-") != std::string::npos)
	{
		std::cerr << "datos" << std::endl;
		return false;
	}
	if (count_chr(str, '-') != 2)
	{
		std::cerr << "Guion" << std::endl;
		return false;
	}
	if (str.at(4) != '-' && str.at(7) != '-')
	{
		std::cerr << "posicion guiones" << std::endl;
		return false;
	}
	return true;
}

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
		std::cout << "paso2 " << std::endl;
	if (!checkFormatDate (str))
		throw std::runtime_error("Incorrect date fromat.");
	_day = extractDay(str);
	_month = extractMonth(str);
	_year = extractYear(str);
}

std::string Date::getDate()
{
	std::string str;
	std::stringstream aux;
	aux << _year;
	aux >> str;
	aux << _month;
	str = str + '-';
	aux >> str;
	aux >>_day;
	str = str + '-';
	aux >> str;
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
