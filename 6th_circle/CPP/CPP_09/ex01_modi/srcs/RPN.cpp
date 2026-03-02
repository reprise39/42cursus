/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:43:27 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/28 13:24:01 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// constructor - destructor

RPN::RPN() : _ans(0) , _formula(""), _rpn_stack()
{
	std::cout << blue << "RPN constructor called" << reset << std::endl;
}

RPN::RPN(char* argv)
{
	std::cout << blue << "RPN constructor called" << reset << std::endl;

	this->_check_valid_input(argv);
	this->_formula = std::string(argv);

	this->_calculate();
	this->_ans = this->_rpn_stack.top();
}

RPN::RPN(const RPN& other)
{
	std::cout << blue << "RPN copy constructor called" << reset << std::endl;
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if(this != &other)
	{
		this->_formula = other._formula;
		this->_rpn_stack = other._rpn_stack;
		this->_ans = other._ans;
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << red <<  "RPN destructor called" << reset << std::endl;
}

// exception
const char* RPN::input_error::what() const throw()
{
	return (this->_msg);
}


// functions

void RPN::print_ans() const
{
	std::cout << "ans = " << (this->_ans) << std::endl;
}

long RPN::get_ans() const
{
	return (this->_ans);
}

bool RPN::_is_my_digit(char argv)
{
	const char acceptc[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	bool ans = false;

	for(size_t i = 0; i < 10 ; i++)
	{
		if(acceptc[i] == argv)
			ans = true;
	}
	return (ans);
}

bool RPN::_is_my_operator(char argv)
{
	const char acceptc[4] = { '+', '-', '*', '/'};
	bool ans = false;

	for(size_t i = 0; i < 4 ; i++)
	{
		if(acceptc[i] == argv)
			ans = true;
	}
	return (ans);
}

bool RPN::_is_my_brank(char argv)
{
	const char acceptc[2] = { ' ', '\t'};
	bool ans = false;

	for(size_t i = 0; i < 2 ; i++)
	{
		if(acceptc[i] == argv)
			ans = true;
	}
	return (ans);
}

void RPN::_check_valid_input(char* input)
{
	size_t now = 0;
	while (input[now] != '\0')
	{
		if(!(_is_my_digit(input[now]) || _is_my_operator(input[now]) || _is_my_brank(input[now])))
			throw RPN::input_error("This program only can use { 0-9, +, -, *, / }");
		now++;
	}
}

static long add(long a, long b)
{
	if (a > INT_MAX - b)
		throw RPN::input_error("Integer overflow ( add )");
	return (a+b);
}

static long substr(long a, long b)
{
	if (a < INT_MIN + b)
		throw RPN::input_error("Integer overflow ( substr )");
	return (a-b);
}

static long mul(long a, long b)
{
	if(a == 0 || b == 0)
		return (0);

	if(a > INT_MAX/b)
		throw RPN::input_error("Integer overflow ( mul )");
	return (a*b);
}

static long dev(long a, long b)
{
	if(b == 0)
		throw RPN::input_error("devide by zero");
	return (a/b);
}

static void _cal_operator(std::stack<long> &st, char op)
{
	if(st.size() < 2)
	{
		throw RPN::input_error("Error : no enough numbers before operator");
	}

	long b = st.top();
	st.pop();
	long bb = st.top();
	st.pop();

	const char ope[4] = {'+', '-', '*', '/'};

	int sw = -1;
	for(int i = 0 ; i < 4 ; i++)
	{
		if(op == ope[i])
			sw = i;
	}
	if(sw == -1)
	{
		throw RPN::input_error("unexpected operator");
	}
	long (*funcp[4])(long,long)  = {add, substr, mul, dev};

	long ans = funcp[sw](bb,b);
	st.push(ans);
}

void RPN::_calculate()
{
	size_t now = 0;

	while(this->_formula[now] != '\0')
	{
		while (this->_is_my_brank(this->_formula[now]))
			++now;
		if (this->_is_my_digit(this->_formula[now]))
		{
			long l = static_cast<long>(this->_formula[now] - '0');
			this->_rpn_stack.push(l);
		}
		else if (this->_is_my_operator(this->_formula[now]))
		{
			_cal_operator(this->_rpn_stack, this->_formula[now]);
		}
		++now;
	}

	if(this->_rpn_stack.size() != 1)
	{
		throw RPN::input_error("Error : can't calculate (luck operator)");
	}
}
