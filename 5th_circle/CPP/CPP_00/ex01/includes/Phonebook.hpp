#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# ifndef CONCAT_HPP
#  include "Contact.hpp"
# endif

// macro
# define BOOK_SIZE 9

class Phonebook
{
	public:
		void add(void);
		void search(void);
	private:
		Contact contact[BOOK_SIZE + 1];
		void move(void);
		void print_list(void);
		void search_list(void);
		void search_x(int index_num);
};

#endif
