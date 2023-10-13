/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/26 21:27:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "main.h"


void print_info (void)
{
	std::cout << "Entrada incorrecta." << std::endl;
	std::cout << "Introduzca 3 parámetros." << std::endl;
	std::cout << "1- Nombre del fichero." << std::endl;
	std::cout << "2- String a reemplazar."<< std::endl;
	std::cout << "2- String de reemplazo."<< std::endl;
}

std::string	replace(char **ac)
{
	std::string filename(ac[1]);
	std::string str1(ac[2]);
	std::string str2(ac[3]);
	std::size_t found = filename.find(str1);
	std::size_t length = str1.length();
	
	while (found != std::string::npos)
	{
		filename.erase(found, length);
		filename.insert(found, str2);
		found = filename.find(str1, found + str2.length());
	}
	return filename;
}

bool cp_content (std::ifstream *file_to_copy, std::string newfilename)
{
	std::string		line;
	std::ofstream	file_copied;
	
	file_copied.open(newfilename, std::ios::out | std::ios::trunc);
	if (!file_copied)
	{
		std::cout << "File couldn't be crated." << std::endl;
		return false;
	}
	while (std::getline(*file_to_copy, line))
		file_copied << line << std::endl;
	return true;
}

int main(int av, char **ac)
{
	std::ifstream	file_to_copy;
	std::string		newfilename;
	std::string		str1;
	std::string		str2;

	if (av < 4)
	{
		print_info();
		return 0;
	}
	file_to_copy.open(ac[1], std::ios::in);
	if(!file_to_copy)
	{
		std::cout << "File " << ac[1] << " does not exist or no access." << std::endl;
		return ( EXIT_FAILURE );
	}
	str1 = ac[2];
	str2 = ac[3];
	if (str1 == str2)
	{
		std::cout << "String to be replaced and replacement are identical." << std::endl;
		return 0;
	}
	newfilename = replace(ac);
	if (newfilename == ac[1])
	{
		std::cout << "String "<< str1 << " not found in " << ac[1];
		std::cout << ", no file generated." << std::endl;
	}
	else
	{
		if (cp_content(&file_to_copy, newfilename))
		{
			std::cout << "El contenido de " << ac[1];
			std::cout << " ha sido copiado en " << newfilename << std::endl;
		}
		file_to_copy.close();
	}
	return 0;
}
