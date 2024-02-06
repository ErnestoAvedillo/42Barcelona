/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:08:19 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/06 13:44:05 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <cmath>

# define MAX_CHAR 255
# define MIN_CHAR 0
# define MIN_CHAR_PRINT 21
# define MAX_CHAR_PRINT 254

enum DATA_TYPE
{
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

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &);
		void	convert(std::string );
		void	ToChar(std::string );
		void	ToInt(std::string );
		void	ToFloat(std::string );
		void	ToDouble(std::string );
};

#endif
