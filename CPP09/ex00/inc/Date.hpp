/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/10 12:55:40 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "../inc/main.hpp"

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
