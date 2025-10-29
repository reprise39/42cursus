/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/29 18:49:48 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(0));
	
	try
	{
		Intern mame;
		Form* f;
		
		//"robotomy request", "presidential pardon", "shrubbery creation"
		f = mame.makeForm("shrubbery creation","mkuida");
	
		
		Bureaucrat ore("ore", 1);
		ore.signForm(*f);
		ore.executeForm(*f);

		delete f;
	}
	catch(std::exception &e)
	{
		std::cout << "in exception : " << e.what() << std::endl;
	}
	
	return 0;
}