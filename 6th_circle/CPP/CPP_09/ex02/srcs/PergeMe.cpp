#include "../includes/PergeMe.hpp"
#include <iostream>
#include <sstream>

PergeMe::PergeMe(std::vector<int>myvec, std::deque<int> mydeq) : _vecint(myvec) , _deqint(mydeq) , _vectime(0) , _deqtime(0), _ans("")
{
	this->_range = myvec.size();
	this->_input = this->vec_to_str();

	this->_mergeInsertSortVec();
	this->_mergeInsertSortDeq();
	this->_ans = this->vec_to_str();
}

PergeMe::PergeMe(const PergeMe& other)
{
	*this = other;
}

PergeMe& PergeMe::operator=(const PergeMe& other)
{
	if(this != &other)
	{
		this->_vecint = other._vecint;
		this->_deqint = other._deqint;
		this->_input = other._input;
		this->_range = other._range;
		this->_ans = other._ans;
		this->_vectime = other._vectime;
		this->_deqtime = other._deqtime;
	}
	return *this;
}

//function
std::string PergeMe::vec_to_str() const
{
	std::ostringstream oss;

	for(size_t i = 0 ; i < this->_range; i++)
	{
		if(i != 0)
			oss << " ";
		oss << this->_vecint[i];
	}
	return oss.str();
}


static void make_pair_vec(std::vector<int>& vec)
{
	if(vec.size() < 2)	
		return;
	
	std::vector<std::pair<int, int> > pairs;

}

void PergeMe::_mergeInsertSortVec()
{
	std::clock_t start = std::clock();

	// merge insert sort for vector
	make_pair_vec(this->_vecint);

	std::clock_t end = std::clock();
	std::clock_t duration = end - start;
	this->_vectime = static_cast<unsigned int>(duration * 1000000 / CLOCKS_PER_SEC);
}

void PergeMe::_mergeInsertSortDeq()
{
	std::clock_t start = std::clock();

	// merge insert sort for deque

	std::clock_t end = std::clock();
	std::clock_t duration = end - start;
	this->_deqtime = static_cast<unsigned int>(duration * 1000000 / CLOCKS_PER_SEC);
}

void PergeMe::printAns() const
{
	std::cout << "Before:  " << this->_input << std::endl;
	std::cout << "After:   " << this->_ans << std::endl;
	std::cout << "Time to process a range of " << this->_range << " elements with std::[vector] : " << this->_vectime << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_range << " elements with std::[deque]  : " << this->_deqtime << " us" << std::endl;
}


// exception
const char* PergeMe::input_error::what() const throw()
{
	return (this->_msg);
}
