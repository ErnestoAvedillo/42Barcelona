/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/16 12:03:14 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock const &);
		Warlock &operator=(Warlock const &);

	public:
		Warlock(std::string &, std::string &);
		Warlock(const std::string &, const std::string &);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string &);
		void setTitle(std::string const &);
		void introduce() const;
};

#endif
