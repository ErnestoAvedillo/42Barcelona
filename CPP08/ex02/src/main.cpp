/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:01:04 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/24 16:35:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

static float getValue(std::string str)
{
	int32_t out = 0;

	std::stringstream ss;
	out = 0;
	if (str.empty())
		throw std::runtime_error("Argument not valid.");
	if (str.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Argument not valid.");
	ss << str;
	ss >> out;
	return out; 
}

void printValues (MutantStack<int> st)
{
	MutantStack<int>::iterator it = st.begin();
	MutantStack<int>::iterator itend = st.end();

	while (it != itend)
		{
			std::cout << *it;
			++it;
			if (it == itend)
				std::cout << ".\n";
			else
				std::cout << ", ";
		}
}

void printValuesInverted (MutantStack<int> st)
{
	MutantStack<int>::iterator it = st.begin();
	MutantStack<int>::iterator itend = st.end();

	itend--;
	while (it != itend)
	{
		std::cout << *itend << ", ";
		--itend;
	}
	std::cout << *itend << ".\n";
}

int main (int av, char **ac)
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		int to_find;
		if (av < 2)
			to_find = 20;
		else
		{
			try
			{
				std::string value(ac[1]);
				to_find = getValue(value);
				if (to_find <= 0)
				{
					std::cout << "Argument " << value << "not valid." << std::endl;
					std::cout << "Only an integer > 0 is valid.(Only numbers)" << std::endl;
					return 0;
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << "No conversion " << e.what() << " to int possible, Bye." << '\n';
				return 0;
			}

		}
		MutantStack<int> val;
		std::cerr << BLUE "Adding values to the stack ." RESET << '\n';

		srand((unsigned int)time((time_t *)NULL));
		for (int i = 0; i <to_find; i++)
		{
			val.push(rand() % to_find);
		}
		printValues(val);

		std::cout << MGENTA "Last number of the stack." RESET << val.top() << std::endl;
		std::cout << CYAN "Size of the stack." RESET << val.size() << std::endl;
		std::cout << YELLOW "Removing last item." RESET << std::endl;
		val.pop();
		std::cout << MGENTA "Last number of the stack." RESET << val.top() << std::endl;
		std::cout << CYAN "Size of the stack." RESET << val.size() << std::endl;
		try
		{
			std::cout << CYAN "Get third value with .at method " RESET << val.at(2) << std::endl;
			std::cout << RED "Get value out of range with .at method:  " RESET << val.at(to_find + 2) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "let's test the inverted iterator. Print  in inverted direction" << std::endl;
		printValuesInverted(val);
	}
}
