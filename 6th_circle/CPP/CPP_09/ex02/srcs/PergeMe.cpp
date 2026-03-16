
#include "PergeMe.hpp"

PergeMe::PergeMe(std::vector<int>myvec, std::deque<int> mydeq) : _vecint(myvec) , _deqint(mydeq)
{
}

//private
PergeMe::PergeMe() : _input("") {}


PergeMe::~PergeMe() {}

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

//
/*
bool PergeMe::is_ui(char* str)
{
	std::istringstream iss(str);
	unsigned int i = 0;

	if(iss)
		return true;
	return false;
}
*/