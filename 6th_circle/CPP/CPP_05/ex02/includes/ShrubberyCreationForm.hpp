/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:06:55 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 19:33:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "sio.hpp"
#include <string>
#include <fstream>

#define SCF_S_GRADE 145
#define SCF_E_GRADE 137
#define SCF_NAME "scf"
#define SCF_TAR "scf-defotar"

class ShrubberyCreationForm : public Form
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& cp);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator =(const ShrubberyCreationForm& other);

		void unqBehave() const;
		std::string getTarget() const throw();
		const std::string strMyClass();

	private :
		std::string _target;
		static std::string _aastr;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm&s );

# endif