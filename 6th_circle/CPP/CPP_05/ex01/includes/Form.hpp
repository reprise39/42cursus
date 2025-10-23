/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:09:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/23 18:45:04 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public :
		Form(std::string name, int sGrade, int eGrade);
		Form(const Form& other);
		~Form();

		std::string getName() const throw();
		bool getIsSign() const throw();
		int getGradeToSign() const throw();
		int getGradeToExecute() const throw();
		
		// for be canonical
		Form& operator=(const Form& other);
		
		// for print
		const std::string strMyClass();

		//exception
		class GradeTooHighException : std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : std::exception
		{
			const char* what() const throw();
		};
		
	private:
		std::string _name;
		bool _isSigned;
		int _gradeToSign;
		int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif