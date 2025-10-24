/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:28:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 19:52:04 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form() : _name(F_DEFO_NAME), _isSigned(false), _gradeToSign(F_DEFO_SGRADE), _gradeToExecute(F_DEFO_EGRADE)
{
	if (F_DEFO_SGRADE < MAX_GRADE || F_DEFO_EGRADE < MAX_GRADE)
		throw(Form::GradeTooHighException());
	if (F_DEFO_SGRADE > MIN_GRADE || F_DEFO_EGRADE > MIN_GRADE)
		throw(Form::GradeTooLowException());

	std::cout << blue
			  << strMyClass() << strConstMsg() << *this << reset << std::endl;
}

Form::Form(std::string name, int sGrade, int eGrade) : _name(name), _isSigned(false), _gradeToSign(sGrade), _gradeToExecute(eGrade)
{
	if (sGrade < MAX_GRADE || eGrade < MAX_GRADE)
		throw(Form::GradeTooHighException());
	if (sGrade > MIN_GRADE || eGrade > MIN_GRADE)
		throw(Form::GradeTooLowException());

	std::cout << blue
			  << strMyClass() << strConstMsg() << *this << reset << std::endl;
}
Form::Form(const Form &other)
{
	*this = other;

	std::cout << blue
			  << strMyClass() << strConstMsg() << *this << reset << std::endl;
}

Form::~Form()
{
	std::cout << red
			  << strMyClass() << strDestMsg() << *this << reset << std::endl;
}

void Form::beSigned(const Bureaucrat &b)
{
	try
	{
		if(this->getGradeToSign() < b.getGrade())
		{
			throw(Form::GradeTooLowException());
		}
		this->_isSigned = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << b.getName() << " couldn’t sign " << this->getName() << " because " << e.what() << std::endl;		
	}
	catch(std::exception& e)
	{
		std::cout << b.getName() << " couldn’t sign " << this->getName() << " because " << e.what() << std::endl;
	}
}

void Form::execute(const Bureaucrat& excuter) const
{
	try
	{
		if(this->getIsSign() == false)
			throw(Form::NoSignException());
		if(this->getGradeToExecute() < excuter.getGrade())
			throw(Form::GradeTooLowException());
		
		this->unqBehave();
		std::cout << excuter.getName() << " executed " << this->getName() << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << excuter.getName() << " couldn’t execute " << this->getName() << " because " << e.what() << std::endl;		
	}
	catch(std::exception& e)
	{
		std::cout << excuter.getName() << " couldn’t execute " << this->getName() << " because " << e.what() << std::endl;
	}
}


std::string Form::getName() const throw()
{
	return (_name);
}

bool Form::getIsSign() const throw()
{
	return (_isSigned);
}

int Form::getGradeToSign() const throw()
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const throw()
{
	return (_gradeToExecute);
}

// for be canonical
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_isSigned = other.getIsSign();
		this->_gradeToSign = other.getGradeToSign();
		this->_gradeToExecute = other.getGradeToExecute();
	}
	return (*this);
}

// for print
const std::string Form::strMyClass()
{
	return ("<class : Form> ");
}

// exception
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade is too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade is too Low");
}

const char *Form::NoSignException::what() const throw()
{
	return ("Form is not signed");
}


//
std::ostream &operator<<(std::ostream &os, const Form &f)
{
	std::ostringstream adstr;
	adstr << f.getName() << ", Form sign-grade = " << f.getGradeToSign() << ", Form ex-grade = " << f.getGradeToExecute();

	return (os << adstr.str());
}
