/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:49 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:40:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string my_name, int my_grade) : _name(my_name) , _grade(my_grade)
{
	if(my_grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if(my_grade > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());

	std::cout << blue
		<< Bureaucrat::strMyClass() << strConstMsg() << "name = " << getName() << ", " << "grade = " << getGrade()
		<< reset << std::endl;
}

Bureaucrat::Bureaucrat(int my_grade, std::string my_name) : _name(my_name) , _grade(my_grade)
{
	if(my_grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if(my_grade > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());

	std::cout << blue
		<< Bureaucrat::strMyClass() << strConstMsg() << "name = " << getName() << ", " << "grade = " << getGrade()
		<< reset << std::endl;
	}

Bureaucrat::Bureaucrat(int my_grade) : _name("no_name") , _grade(my_grade)
{
	if(my_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if(my_grade > 150)
		throw (Bureaucrat::GradeTooLowException());

	std::cout << blue
		<< Bureaucrat::strMyClass() << strConstMsg() << "name = " << getName() << ", " << "grade = " << getGrade()
		<< reset << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;

	std::cout << blue
		<< Bureaucrat::strMyClass() << strConstMsg() << "name = " << getName() << ", " << "grade = " << getGrade()
		<< reset << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << red 
		<< Bureaucrat::strMyClass() << strDestMsg() << "name = " << getName() << ", " << "grade = " << getGrade()
		<< reset << std::endl;
}

void Bureaucrat::signForm(Form& f) const
{
	f.beSigned(*this);
}


const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string Bureaucrat::strMyClass()
{
	return ("<class : Bureaucrat> ");
}

void Bureaucrat::GradeUp()
{
	if(this->_grade == MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	
	this->_grade = this->getGrade() - 1;
}

void Bureaucrat::GradeDown()
{
	if(this->_grade == MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());

	this->_grade = this->getGrade() + 1;
}

// for canonical
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}


// for exception class

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Grade is too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Grade is too Low");
}

std::ostream& operator <<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ", bureaucrat grade" << b.getGrade());
}
