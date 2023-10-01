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
		found = filename.find(str1);
	}
	return filename;
}

int main(int av, char **ac)
{
	std::fstream	file_to_copy;
	std::fstream	file_copied;
	std::string		newfilename;
	std::string		filecontent;
	std::string		line;

	if (av < 4)
	{
		print_info();
		return 0;
	}
	file_to_copy.open(ac[1], std::ios::in);
	if(!file_to_copy)
	{
		std::cout << "File " << ac[1] << " does not exist." << std::endl;
		return ( EXIT_FAILURE );
	}
	newfilename = replace(ac);
	if (newfilename == ac[1])
		std::cout << "String no encontrada, nuevo fichero no generado" << std::endl;
	else
	{
		file_copied.open(newfilename, std::ios::out);
		while (std::getline(file_to_copy, line))
			file_copied << line << std::endl;
		file_copied.close();
		file_to_copy.close();
		std::cout << "El contenido de " << ac[1];
		std::cout << " ha sido copiado en " << newfilename << std::endl;
	}
	return 0;
}
