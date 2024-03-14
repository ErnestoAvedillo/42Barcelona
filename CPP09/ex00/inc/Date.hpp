/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 10:07:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "../inc/utils.hpp"

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

std::ostream &operator<<(std::ostream &ost, Date const &d);

#endif
