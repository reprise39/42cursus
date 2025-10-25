/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:20:25 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 22:21:47 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
	std::cout << blue
		<< strMyClass() << strConstMsg() << reset << std::endl;
}

Intern::Intern(const Intern& cp)
{
	(void) cp;
	std::cout << blue
		<< strMyClass() << strConstMsg() << reset << std::endl;
}

Intern::~Intern()
{
	std::cout << red
		<< strMyClass() << strDestMsg() << reset << std::endl;
}

Intern& Intern::operator=(const Intern& cp)
{
	(void)cp;
	return (*this);
}

std::string Intern::strMyClass() const
{
	return ("<class : Intern> ");
}

static Form* mkPPF(std::string tar)
{
	Form* rtn= new PresidentialPardonForm(tar);
	return (rtn);
}

static Form* mkRRF(std::string tar)
{
	Form* rtn= new RobotomyRequestForm(tar);
	return (rtn);
}

static Form* mkSCF(std::string tar)
{
	Form* rtn= new ShrubberyCreationForm(tar);
	return (rtn);
}

Form* Intern::makeForm(std::string formstr, std::string tar)
{
	Form* (*f[])(std::string)={mkPPF,mkRRF,mkSCF};
	Form* rtn = NULL;

	std::string forms[3] = 
	{
		"robotomy request", "presidential pardon", "shrubbery creation"
	};
	
	for(int i = 0 ; i < 3 ; i++)
	{
		if(formstr == forms[i])
			rtn = f[i](tar);
	}
	if(rtn == NULL)
		throw(Intern::NoFormException());
	else
	{
		std::cout << "Intern make" << *rtn << std::endl;
		return (rtn);
	}
}

const char* Intern::NoFormException::what() const throw()
{
	return ("target form is nowhere (;-;)");
} 
