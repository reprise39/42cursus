/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:43:27 by mkuida            #+#    #+#             */
/*   Updated: 2025/11/08 00:58:44 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool is_my_digit(char argv)
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

bool is_my_operator(char argv)
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

bool is_my_brank(char argv)
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

static long add(long a, long b)
{
	return (a+b);
}

static long substr(long a, long b)
{
	return (a-b);
}

static long mul(long a, long b)
{
	return (a*b);
}

static long dev(long a, long b)
{
	if(b == 0)
	{
		std::cout << "Error : devide by zero" << std::endl;
		exit (1);
	}
	return (a/b);
}


bool cal_operator(std::stack<long> &st, char op)
{
	if(st.size() < 2)
	{
		std::cout << "size-less : size = " << st.size() << std::endl;
		return false;
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
		std::cout << "no-sw" << std::endl;
		return false;
	}
	long (*funcp[4])(long,long)  = {add, substr, mul, dev};

	long ans = funcp[sw](bb,b);
	st.push(ans);
	return (true);
}

void print_ans(std::stack<long> st)
{
	if(st.size() > 1)
	{
		std::cout << "Error : cant cal (luck operator)" << std::endl;
	}
	if(st.size() == 1)
	{
		std::cout << st.top() << std::endl;
	}
}

void cal(char* argv)
{
	std::string str(argv);
	std::stack<long> st;
	size_t now = 0;

	while(argv[now] != '\0')
	{
		while (is_my_brank(argv[now]))
			++now;
		if (is_my_digit(argv[now]))
		{
			long l = static_cast<long>(argv[now] - '0');
			st.push(l);
			++now;
		}
		else if (is_my_operator(argv[now]))
		{
			if(cal_operator(st,argv[now]) == false)
			{
				std::cout << "ope fail " << std::endl;
				return ;
			}
			++now;
		}
		else
		{
			std::cout << "??" << std::endl;
		}
	}
	print_ans(st);
}
