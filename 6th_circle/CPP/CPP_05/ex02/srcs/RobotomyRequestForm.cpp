/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:51:20 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 20:33:00 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form(RRF_NAME, RRF_S_GRADE, RRF_E_GRADE) , _target(RRF_TAR)
{
	if (RRF_S_GRADE < MAX_GRADE || RRF_S_GRADE < MAX_GRADE)
		throw(Form::GradeTooHighException());
	if (RRF_E_GRADE > MIN_GRADE || RRF_E_GRADE > MIN_GRADE)
		throw(Form::GradeTooLowException());

	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(RRF_NAME, RRF_S_GRADE, RRF_E_GRADE) , _target(target)
{
	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cp) : Form(cp)
{
	if(this != &cp)
		this->_target = cp.getTarget();

	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << red
			  << strMyClass() << strDestMsg() << *this << reset << std::endl;
}

std::string RobotomyRequestForm::getTarget() const throw()
{
	return (this->_target);
}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& other)
{
	Form::operator=(other);
	if(this != &other)
		this->_target = other.getTarget();

	return (*this);
}

void RobotomyRequestForm::unqBehave() const
{
	int fifty = rand() % 2;

	if(fifty == 0)
	{
		std::cout << "robotomy-success : " << this->getTarget() << " has been robotomized" << std::endl;
	}
	else
		throw(RobotomyRequestForm::RobofailException());
}

const std::string RobotomyRequestForm::strMyClass()
{
	return ("<class : RobotomyRequestForm> ");		
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm&p )
{
	std::ostringstream adstr;
	adstr << p.getName() << ", Form sign-grade = " << p.getGradeToSign() << ", Form ex-grade = " << p.getGradeToExecute() << ", target = " << p.getTarget();

	return (os << adstr.str());
}

const char* RobotomyRequestForm::RobofailException::what() const throw()
{
	return ("robotomy-operation-failed (>-<..)");
}
