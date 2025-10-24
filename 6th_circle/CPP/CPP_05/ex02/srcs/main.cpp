/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 20:33:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	srand(time(0));

	Bureaucrat ore("ore", 1);
	ShrubberyCreationForm scform("backup");
	PresidentialPardonForm ppform("prison break");
	RobotomyRequestForm rrform("mkuida");
	
	ore.signForm(scform);
	ore.signForm(ppform);
	ore.signForm(rrform);


	ore.executeForm(scform);
	ore.executeForm(ppform);
	//
	ore.executeForm(rrform);
	ore.executeForm(rrform);
	ore.executeForm(rrform);
	ore.executeForm(rrform);
	ore.executeForm(rrform);

	return 0;
}