#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

class Date
{
    private:
        int _day;
        int _month;
        int _year;

    public:
    Date();
    Date(std::string  const &);
    Date(Date const &);
    Date &operator=(Date const &);
    ~Date();
    bool operator==(const Date &) const;
    bool operator>(const Date &) const;
    bool operator<(const Date &) const;
    bool operator<=(const Date &) const;
    bool operator>=(const Date &) const;
    void putDate(std::string const &);
    std::string getDate();
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};

#endif
