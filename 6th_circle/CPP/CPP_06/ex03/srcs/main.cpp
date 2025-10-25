/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 22:24:28 by mkuida           ###   ########.fr       */
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
		Form* rrf;
		
		rrf = mame.makeForm("robotomy requesta","skuida");
	
		
		Bureaucrat ore("ore", 1);
		// ShrubberyCreationForm scform("backup");
		// PresidentialPardonForm ppform("prison break");
		ore.signForm(*rrf);
		ore.executeForm(*rrf);

		delete rrf;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}