/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/29 17:56:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	//prep
	srand(time(0));
	Bureaucrat ore("ore", 1);

	//scform
	ShrubberyCreationForm scform("./objs/");
	// ShrubberyCreationForm scform("no_write_outh");
	ore.signForm(scform);
	ore.executeForm(scform);

	//ppform
	PresidentialPardonForm ppform("prison break");
	ore.signForm(ppform);
	ore.executeForm(ppform);

	//rrform
	RobotomyRequestForm rrform("mkuida");
	ore.signForm(rrform);

	for(int i = 0; i < 1 ; i++)
		ore.executeForm(rrform);
	
	return 0;
}