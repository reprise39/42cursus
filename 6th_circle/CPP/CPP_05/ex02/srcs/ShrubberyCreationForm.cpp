/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:51:20 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 19:37:06 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string ShrubberyCreationForm::_aastr = 
		"my full power aa\n\n"
		"    ^      \n"
		"   / \\     \n"
		"  /   \\    \n"
		" /     \\   \n"
		"/=======\\  \n"
		"    |      \n";


ShrubberyCreationForm::ShrubberyCreationForm() : Form(SCF_NAME, SCF_S_GRADE, SCF_E_GRADE) , _target(SCF_TAR)
{
	if (SCF_S_GRADE < MAX_GRADE || SCF_S_GRADE < MAX_GRADE)
		throw(Form::GradeTooHighException());
	if (SCF_E_GRADE > MIN_GRADE || SCF_E_GRADE > MIN_GRADE)
		throw(Form::GradeTooLowException());

	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(SCF_NAME, SCF_S_GRADE, SCF_E_GRADE) , _target(target)
{
	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cp) : Form(cp)
{
	if(this != &cp)
		this->_target = cp.getTarget();
	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << red
			  << strMyClass() << strDestMsg() << *this << reset << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const throw()
{
	return (this->_target);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& other)
{
	Form::operator=(other);
	if(this != &other)
		this->_target = other.getTarget();

	return (*this);
}

void ShrubberyCreationForm::unqBehave() const
{
	std::ofstream ofile;
	// in_deforlt dont throw
	ofile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	std::string filename = this->getTarget() + "_shrubbery";	
	ofile.open(filename.c_str());	
	ofile << _aastr;
	ofile.close();
	return;
}

const std::string ShrubberyCreationForm::strMyClass()
{
	return ("<class : ShrubberyCreationForm> ");
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm&s )
{
	std::ostringstream adstr;
	adstr << s.getName() << ", Form sign-grade = " << s.getGradeToSign() << ", Form ex-grade = " << s.getGradeToExecute() << ", target = " << s.getTarget();

	return (os << adstr.str());
}
