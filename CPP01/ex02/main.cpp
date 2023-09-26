/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main (void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPtr = &str;
	std::string	&stringRef = str;

	std::cout << "str Pointer value: " << &str << std::endl;
	std::cout << "str String value: " << str << std::endl;
	std::cout << "stringPtr Pointer value: " << stringPtr << std::endl;
	std::cout << "stringPtr String value: " << *stringPtr << std::endl;
	std::cout << "stringRef Pointer value : " << &stringRef << std::endl;
	std::cout << "stringRef String value : " << stringRef << std::endl;
}
