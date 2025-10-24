/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:44:11 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 16:56:46 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

//include inb
# include "sio.hpp"
# include "Form.hpp"

//def macro
//1 is upperest
# define MAX_GRADE 1
# define MIN_GRADE 150
# define B_DEFO_NAME "mkuida"
# define B_DEFO_GRADE 42

class Form;

//def myClass
class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int my_grade);
		Bureaucrat(int my_grade, std::string name);
		Bureaucrat(int my_grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		void signForm(Form& f) const;

		const std::string& getName() const;
		int getGrade() const;

		void GradeUp();
		void GradeDown();

		// for be canonical
		Bureaucrat& operator=(const Bureaucrat& other);
		
		// for print
		const std::string strMyClass();

		// exception class
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	protected:
		std::string _name;
		int _grade;
};

std::ostream& operator <<(std::ostream& os, const Bureaucrat& b);

#endif
