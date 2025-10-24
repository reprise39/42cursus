/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:46:26 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 22:11:14 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

class Form;

class Intern
{
	public:
		Intern();
		Intern(const Intern& cp);
		~Intern();
		Intern& operator=(const Intern& cp);

		std::string strMyClass() const;

		Form* makeForm(std::string formstr, std::string tar);

		class NoFormException : public std::exception
		{
			const char* what() const throw(); 
		};
};


#endif

