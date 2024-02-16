/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:08:19 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/16 16:14:39 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
#include <sstream>
# include <cmath>

# define MAX_CHAR 255
# define MIN_CHAR 0
# define MIN_CHAR_PRINT 33
# define MAX_CHAR_PRINT 126
typedef struct s_convert
{
	int 	type;
	unsigned char c;
	int 	i;
	float 	f;
	double 	d;
	std::string s;
	bool	is_spec;
} t_convert;

typedef t_convert (*Check_func)(std::string);
typedef void (*Conv_funct)(t_convert);

enum DATA_TYPE
{
	NO_TYPE,
	IS_CHAR,
	IS_INT,
	IS_FLOAT,
	IS_DOUBLE,
	MAX_CONVERTS
};
#define INF_MINUS_TYPE {"-inf", "-inff"}
#define INF_TYPE {"inf", "inff"}
#define NAN_TYPE {"nanf", "nan"}

template <typename T, size_t N>
size_t array_size(T (&)[N])
{
	return N;
}

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &);
		static void isChar(t_convert);
		static void isInt(t_convert);
		static void isFloat(t_convert);
		static void isDouble(t_convert);
		static void prtOut(t_convert);
		
	public:
		static void convert(std::string );

};

#endif
