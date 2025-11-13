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
	std::cout << "==== < in-subject test > ====" << std::endl;
	{
	MutantStack<int> mstack;
	mstack.push(5); // 5 <- my-memo
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

	// my-test (1)
	std::cout << "==== < my-test-deq > ====" << std::endl;
	{
		std::deque<int> deq;
		deq.push_back(5);  // 5
		deq.push_front(10); // 10 5
		deq.push_back(15); // 10 5 15
		deq.pop_front(); // 5 15

		std::deque<int>::iterator it = deq.begin();
		std::deque<int>::iterator ite = deq.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	// my-test (2)
	std::cout << "==== < my-test-mstack > ====" << std::endl;
	{
		MutantStack<int> msk;
		msk.push(5);  // 5
		msk.push(10); // 5 10
		msk.push(15); // 5 10 15
		msk.pop(); // 5 10

		MutantStack<int>::reverse_iterator it = msk.rbegin();
		MutantStack<int>::reverse_iterator ite = msk.rend();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}

