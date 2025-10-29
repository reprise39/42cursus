/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/29 17:13:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n=== 00 : basic Bureaucrat ===" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << "Created: " << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception while creating Alice: " << e.what() << std::endl;
	}

	std::cout << "\n=== 01 : Bureaucrat toohigh Grade ===" << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0); //
		std::cout << "ERROR: constructing TooHigh should have thrown." << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught GradeTooHighException as expected: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught other exception (unexpected): " << e.what() << std::endl;
	}

	std::cout << "\n=== 02 : Bureaucrat toolow Grade===" << std::endl;
	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << "ERROR: constructing TooLow should have thrown." << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught GradeTooLowException : " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught other exception (unexpected): " << e.what() << std::endl;
	}

	std::cout << "\n=== 03 : Grade up ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << "Initial: " << bob << std::endl;

		bob.GradeUp();
		std::cout << "After increment: " << bob << std::endl;

		std::cout << "will error..." << std::endl;
		bob.GradeUp(); //!!!
		std::cout << "ERROR: increment did not throw when expected." << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "error test: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "error test(unexpect): " << e.what() << std::endl;
	}

	std::cout << "\n=== 04 : Grade down ===" << std::endl;
	try
	{
		Bureaucrat carol("Carol", 149);
		std::cout << "Initial: " << carol << std::endl;

		carol.GradeDown();
		std::cout << "After decrement: " << carol << std::endl;

		std::cout << "Attempting one more decrement (should throw)..." << std::endl;
		carol.GradeDown(); // !!!
		std::cout << "ERROR: decrement did not throw when expected." << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught GradeTooLowException during decrement test: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught other exception during decrement test: " << e.what() << std::endl;
	}

	std::cout << "\n=== 05 : Canonical ===" << std::endl;
	try
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copy = original;
		std::cout << "Original: " << original << " | Copy: " << copy << std::endl;

		original.GradeUp(); // original -> 49
		std::cout << "After original.increment()\nOriginal: " << original << "\nCopy: " << copy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception during copy test: " << e.what() << std::endl;
	}

	return 0;
}