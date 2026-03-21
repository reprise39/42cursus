/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:36:29 by mkuida            #+#    #+#             */
/*   Updated: 2026/03/21 19:45:50 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <cstdlib>
# include <iostream>
# include <climits>

// void cal(char* argv);
void cal(char* argv);

class RPN
{
	public:
		//canonical form
		RPN();
		RPN(char* input);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		//functions
		void print_ans() const;
		long get_ans() const;

		//exception
		class input_error : public std::exception
		{
			public:
				input_error(const char* msg) : _msg(msg) {}
				const char* what() const throw();
			private:
				const char* _msg;
		};

	private:
		long _ans;
		std::string _formula;
		std::stack<long> _rpn_stack;

		void _check_valid_input(char* input);
		void _calculate();
		bool _is_my_digit(char argv);
		bool _is_my_operator(char argv);
		bool _is_my_brank(char argv);
};

std::ostream& red(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& reset(std::ostream& os);

#endif
