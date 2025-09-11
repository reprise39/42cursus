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
		void init_phonebook();
		Contact contact[BOOK_SIZE + 1];
	private:
};

#endif
