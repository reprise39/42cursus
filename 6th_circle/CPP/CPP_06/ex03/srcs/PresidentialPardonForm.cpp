/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:51:20 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 19:37:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(PPF_NAME, PPF_S_GRADE, PPF_E_GRADE) , _target(PPF_TAR)
{
	if (PPF_S_GRADE < MAX_GRADE || PPF_S_GRADE < MAX_GRADE)
		throw(Form::GradeTooHighException());
	if (PPF_E_GRADE > MIN_GRADE || PPF_E_GRADE > MIN_GRADE)
		throw(Form::GradeTooLowException());

	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(PPF_NAME, PPF_S_GRADE, PPF_E_GRADE) , _target(target)
{
	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cp) : Form(cp)
{
	if(this != &cp)
		this->_target = cp.getTarget();

	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << red
			  << strMyClass() << strDestMsg() << *this << reset << std::endl;
}

std::string PresidentialPardonForm::getTarget() const throw()
{
	return (this->_target);
}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& other)
{
	Form::operator=(other);
	if(this != &other)
		this->_target = other.getTarget();

	return (*this);
}

void PresidentialPardonForm::unqBehave() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const std::string PresidentialPardonForm::strMyClass()
{
	return ("<class : PresidentialPardonForm> ");
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm&p )
{
	std::ostringstream adstr;
	adstr << p.getName() << ", Form sign-grade = " << p.getGradeToSign() << ", Form ex-grade = " << p.getGradeToExecute() << ", target = " << p.getTarget();

	return (os << adstr.str());
}
