#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <iterator>

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

//###############################################################################################
//       vector sort
//###############################################################################################

// static void dev_print_vec(std::string name, std::vector<int> vec)
// {
// 	std::cout << name << ": ";
// 	for(size_t i = 0; i < vec.size(); i++)
// 	{
// 		if(i != 0)
// 			std::cout << " ";
// 		std::cout << vec[i];
// 	}
// 	std::cout << std::endl;
// }

static int search_pair_vec(int search, std::vector<std::pair<int, int> > pairs)
{
	size_t i = 0;
	while(i < pairs.size())
	{
		if(pairs[i].first == search)
			return (pairs[i].second);
		i++;
	}
	throw std::runtime_error("search_pair: unmatch error");
}

static std::vector<int> get_insert_bignum_vec(std::vector<int> chain)
{
	std::vector<int> fj;
	fj.push_back(0);
	fj.push_back(1);

	while(fj.back() < static_cast<int>(chain.size()))
	{
		int size = fj.size();
		fj.push_back(fj[size-1] + fj[size-2] * 2);
	}

	std::vector<int> ans;
#if RESERVE_MODE
	ans.reserve(chain.size());
#endif
	for(int i = 1; i < static_cast<int>(fj.size()); i++)
	{
		int curr = fj[i];
		int prev = fj[i-1];

		for(int j = curr - 1; j >= prev; j--)
		{
			if(j >= 0 && j < static_cast<int>(chain.size()))
				ans.push_back(chain[j]);
		}
	}
	return ans;
}

static int search_index_vec(int search, std::vector<int> vec)
{
	int i = 0;
	std::vector<int>::iterator itr = vec.begin();
	while(itr != vec.end() && *itr != search)
	{
		itr++;
		i++;
	}
	if (itr == vec.end())
		throw std::runtime_error("search_index: unmatch error");
	return i;
}

static void binary_insert_vec(std::vector<int> &vec, int value, int upper)
{
	int left = 0;
	int right = upper;
	while(left < right)
	{
		int mid = left + (right - left)/2;
		if(vec[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, value);
}

static std::vector<int> make_chain_rec_vec(std::vector<int> vec)
{
	if(vec.size() < 2)
		return vec;

	bool odd_size = false;
	int extra = -1;

	if(vec.size() % 2 == 1)
	{
		odd_size = true;
		extra = vec.back();
		vec.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
#if RESERVE_MODE
	pairs.reserve(vec.size() / 2);
#endif
	for(size_t i = 0 ; i < vec.size() ; i += 2)
	{
		int big = vec[i];
		int small = vec[i+1];
		if(big < small)
			std::swap(big, small);
		pairs.push_back(std::make_pair(big, small));
	}

	int pairs_size = pairs.size();
	std::vector<int> bigger_chain;
#if RESERVE_MODE
	bigger_chain.reserve(pairs_size);
#endif
	for(int i = 0; i < pairs_size; i++)
	{
		bigger_chain.push_back(pairs[i].first);
	}

	// recursive
	std::vector<int> sorted_main = make_chain_rec_vec(bigger_chain);
#if RESERVE_MODE
	sorted_main.reserve(vec.size());
#endif

	std::vector<int> insert_wait_bg = get_insert_bignum_vec(sorted_main);
	for(size_t i = 0 ; i < insert_wait_bg.size() ; i++)
	{
		int upper_index = search_index_vec(insert_wait_bg[i], sorted_main);
		int search = search_pair_vec(insert_wait_bg[i], pairs);

		binary_insert_vec(sorted_main, search, upper_index);
	}

	// last
	if(odd_size)
		binary_insert_vec(sorted_main, extra, sorted_main.size());
	return (sorted_main);
}

void PergeMe::_mergeInsertSortVec()
{
	std::clock_t start = std::clock();

	this->_vecint = make_chain_rec_vec(this->_vecint);

	std::clock_t end = std::clock();
	std::clock_t duration = end - start;
	this->_vectime = static_cast<unsigned int>(duration * 1000000 / CLOCKS_PER_SEC);
}

//###############################################################################################
//       deque sort
//###############################################################################################

static int search_pair_deq(int search, std::vector<std::pair<int, int> > pairs)
{
	size_t i = 0;
	while(i < pairs.size())
	{
		if(pairs[i].first == search)
			return (pairs[i].second);
		i++;
	}
	throw std::runtime_error("search_pair: unmatch error");
}

static std::deque<int> get_insert_bignum_deq(std::deque<int> chain)
{
	std::deque<int> fj;
	fj.push_back(0);
	fj.push_back(1);

	while(fj.back() < static_cast<int>(chain.size()))
	{
		int size = fj.size();
		fj.push_back(fj[size-1] + fj[size-2] * 2);
	}

	std::deque<int> ans;
	for(int i = 1; i < static_cast<int>(fj.size()); i++)
	{
		int curr = fj[i];
		int prev = fj[i-1];

		for(int j = curr - 1; j >= prev; j--)
		{
			if(j >= 0 && j < static_cast<int>(chain.size()))
				ans.push_back(chain[j]);
		}
	}
	return ans;
}

static int search_index_deq(int search, std::deque<int> deq)
{
	int i = 0;
	std::deque<int>::iterator itr = deq.begin();
	while(itr != deq.end() && *itr != search)
	{
		itr++;
		i++;
	}
	if (itr == deq.end())
		throw std::runtime_error("search_index: unmatch error");
	return i;
}

static void binary_insert_deq(std::deque<int> &deq, int value, int upper)
{
	int left = 0;
	int right = upper;
	while(left < right)
	{
		int mid = left + (right - left)/2;
		if(deq[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	deq.insert(deq.begin() + left, value);
}

static std::deque<int> make_chain_rec_deq(std::deque<int> deq)
{
	if(deq.size() < 2)
		return deq;

	bool odd_size = false;
	int extra = -1;

	if(deq.size() % 2 == 1)
	{
		odd_size = true;
		extra = deq.back();
		deq.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
#if RESERVE_MODE
	pairs.reserve(deq.size() / 2);
#endif
	for(size_t i = 0 ; i < deq.size() ; i += 2)
	{
		int big = deq[i];
		int small = deq[i+1];
		if(big < small)
			std::swap(big, small);
		pairs.push_back(std::make_pair(big, small));
	}

	int pairs_size = pairs.size();
	std::deque<int> bigger_chain;
	for(int i = 0; i < pairs_size; i++)
	{
		bigger_chain.push_back(pairs[i].first);
	}

	// recursive
	std::deque<int> sorted_main = make_chain_rec_deq(bigger_chain);

	std::deque<int> insert_wait_bg = get_insert_bignum_deq(sorted_main);
	for(size_t i = 0 ; i < insert_wait_bg.size() ; i++)
	{
		int upper_index = search_index_deq(insert_wait_bg[i], sorted_main);
		int search = search_pair_deq(insert_wait_bg[i], pairs);

		binary_insert_deq(sorted_main, search, upper_index);
	}

	// last
	if(odd_size)
		binary_insert_deq(sorted_main, extra, sorted_main.size());
	return (sorted_main);
}

void PergeMe::_mergeInsertSortDeq()
{
	std::clock_t start = std::clock();

	this->_deqint = make_chain_rec_deq(this->_deqint);

	std::clock_t end = std::clock();
	std::clock_t duration = end - start;
	this->_deqtime = static_cast<unsigned int>(duration * 1000000 / CLOCKS_PER_SEC);
}

//###############################################################################################
//       other
//###############################################################################################

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

//sio
std::ostream& red(std::ostream& os)
{
	return (os << "\033[31m");
}

std::ostream& blue(std::ostream& os)
{
	return (os << "\033[34m");
}

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}
