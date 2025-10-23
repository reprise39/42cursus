/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:28:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/23 18:47:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int sGrade, int eGrade) : _name(name), _isSigned(false), _gradeToSign(sGrade), _gradeToExecute(eGrade)
{
	if(sGrade < MAX_GRADE || eGrade < MAX_GRADE)
		throw (Form::GradeTooHighException());
	if(sGrade > MIN_GRADE || eGrade > MIN_GRADE)
		throw (Form::GradeTooLowException());

	std::cout << blue
		<< strMyClass() << strConstMsg() << *this << reset << std::endl;
}
Form::Form(const Form& other)
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

std::string Form::getName() const throw()
{
	return (_name);
}

bool Form::getIsSign() const throw()
{
	return (_isSigned);
}

int getGradeToSign() const throw()
{
	return (_gradeToSign);
}

int getGradeToExecute() const throw()
{
	return (_gradeToExcute);
}

// for be canonical
Form& operator=(const Form& other)
{
	if(*this != other)
	{
		this->_name = other.getName();
		this->_isSigned = other.getIsSigned();
		this->_gradeToSign = other.getGradeToSign();
		this->_gradeToExcute = other.getGradeToExecute();
	}
	return (*this);
}

// for print
const std::string strMyClass()
{
	return ("<class : Bureaucrat> ");
}

//exception
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade is too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade is too Low");
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	return (os << f.getName() << ", Form sign-grade = " << f.getGradeToSign << ", Form ex-grade = " << f.getGradeToExecute);
}