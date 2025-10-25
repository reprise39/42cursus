/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:06:55 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 18:03:35 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "sio.hpp"
#include <string>
#include <fstream>

#define PPF_S_GRADE 25
#define PPF_E_GRADE 5
#define PPF_NAME "ppf"
#define PPF_TAR "ppf-defotar"

class PresidentialPardonForm : public Form
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& cp);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator =(const PresidentialPardonForm& other);

		void unqBehave() const;
		std::string getTarget() const throw();
		const std::string strMyClass();

	private :
		std::string _target;
		static std::string _aastr;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm&s );

# endif