/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:09:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 16:59:10 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "sio.hpp"
#include "Bureaucrat.hpp"

# define F_DEFO_NAME "mkuidaform"
# define F_DEFO_SGRADE 42
# define F_DEFO_EGRADE 42

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string name, int sGrade, int eGrade);
	Form(const Form &other);
	~Form();

	void beSigned(const Bureaucrat &b);

	std::string getName() const throw();
	bool getIsSign() const throw();
	int getGradeToSign() const throw();
	int getGradeToExecute() const throw();

	// for be canonical
	Form &operator=(const Form &other);

	// for print
	const std::string strMyClass();

	// exception
	class GradeTooHighException : public std::exception
	{
		public : 
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			const char *what() const throw();
	};

private:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif