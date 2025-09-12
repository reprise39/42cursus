#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	public:
		void set_first_name(std::string);
		void set_last_name(std::string);
		void set_nickname(std::string);
		void set_phone_number(std::string);
		void set_darkest_seclet(std::string);

		std::string get_first_name(void)const;
		std::string get_last_name(void)const;
		std::string get_nickname(void)const;
		std::string get_phone_number(void)const;
		std::string get_darkest_seclet(void)const;

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string phone_number;
		std::string darkest_seclet;
};

#endif
