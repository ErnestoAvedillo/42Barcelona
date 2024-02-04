/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:36:32 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/04 19:16:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "../inc/main.h"
# include "../inc/Form.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(Intern &);
		~Intern();
		Intern &operator=(Intern &);
		Form *makeForm(std::string, std::string);
};
#endif
