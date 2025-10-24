/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 13:47:18 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n=== 00 : basic Form ===" << std::endl;
	try
	{
		Form f("FormA", 42, 75); // (name,sign,excute)
		std::cout << "Created: " << f << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception while creating FormA: " << e.what() << std::endl;
	}

	std::cout << "\n=== 01 : too high sign grade ===" << std::endl;
	try
	{
		Form f("TooHighSign", 0, 50); // !!!
		std::cout << "ERROR: constructing TooHighSign should have thrown." << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "Caught GradeTooHighException as expected: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught other exception (unexpected): " << e.what() << std::endl;
	}

	std::cout << "\n=== 02 : too low sign grade ===" << std::endl;
	try
	{
		Form f("TooLowSign", 151, 100); // !!!
		std::cout << "ERROR: constructing TooLowSign should have thrown." << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "Caught GradeTooLowException as expected: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught other exception (unexpected): " << e.what() << std::endl;
	}

	std::cout << "\n=== 03 : too high execute grade ===" << std::endl;
	try
	{
		Form f("TooHighExec", 100, 0); //
		std::cout << "ERROR: constructing TooHighExec should have thrown." << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "Caught GradeTooHighException as expected: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught other exception (unexpected): " << e.what() << std::endl;
	}

	std::cout << "\n=== 04 : too low execute grade ===" << std::endl;
	try
	{
		Form f("TooLowExec", 100, 151); // 
		std::cout << "ERROR: constructing TooLowExec should have thrown." << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "Caught GradeTooLowException as expected: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught other exception (unexpected): " << e.what() << std::endl;
	}

	std::cout << "\n=== 05 : Canonical form ===" << std::endl;
	try
	{
		Form original("OriginalForm", 50, 75);
		std::cout << "Original: " << original << std::endl;

		Form copy = original; // copy
		std::cout << "Copy: " << copy << std::endl;

		Form assigned("Temp", 100, 100);
		assigned = original; // operator = 
		std::cout << "Assigned: " << assigned << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception during copy/assign test: " << e.what() << std::endl;
	}

	std::cout << "\n=== 06 : operator<< output check ===" << std::endl;
	try
	{
		Form form("DisplayForm", 42, 24);
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception during display test: " << e.what() << std::endl;
	}

	{
	std::cout << "\n=== 07 : sign ===" << std::endl;
	Bureaucrat mkuida("mkuida", 43);
	Form exam("exam", 42, 42);
	mkuida.signForm(exam);
	exam.beSigned(mkuida);
	}

	{
	std::cout << "\n=== 08 : sign ===" << std::endl;
	Bureaucrat mkuida("mkuida", 42);
	Form exam("exam", 42, 42);
	mkuida.signForm(exam);
	exam.beSigned(mkuida);
	}
	
	return 0;
}