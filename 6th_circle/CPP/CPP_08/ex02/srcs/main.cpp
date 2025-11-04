/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:44 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:40:44 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main()
{
	// in-subject test
	{
	MutantStack<int> mstack;
	mstack.push(5); // 5
	mstack.push(17); // 5 17
	std::cout << mstack.top() << std::endl;
	mstack.pop(); // 5
	std::cout << mstack.size() << std::endl;
	mstack.push(3); // 5 3
	mstack.push(5); // 5 3 5
	mstack.push(737); // 5 3 5 737
	//[...]
	mstack.push(0); // 5 3 5 737 0
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	}

	// my-test ()
	std::cout << "==== < my-test > ====" << std::endl;
	{
		std::deque<int> deq;
		deq.push_back(5);  // 5
		deq.push_front(10); // 10 5
		deq.push_back(15); // 10 5 15
		deq.pop_front(); // 5 15

		std::deque<int>::iterator it = deq.begin();
		std::deque<int>::iterator ite = deq.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}

