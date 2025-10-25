/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:06:55 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/24 20:23:35 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "sio.hpp"
#include <string>
#include <ctime>
#include <cstdlib>

#define RRF_S_GRADE 72
#define RRF_E_GRADE 45
#define RRF_NAME "ref"
#define RRF_TAR "ref-defotar"

class RobotomyRequestForm : public Form
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& cp);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator =(const RobotomyRequestForm& other);

		void unqBehave() const;
		std::string getTarget() const throw();
		const std::string strMyClass();

		class RobofailException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private :
		std::string _target;
		static std::string _aastr;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm&s );

# endif