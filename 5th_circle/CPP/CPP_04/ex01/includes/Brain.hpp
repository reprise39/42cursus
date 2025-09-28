/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:53:14 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/28 14:19:59 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "sio.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain &c);
		~Brain();
		Brain& operator=(const Brain& other);

		void setIdea(const int inum , const std::string &str);
		std::string getIdea(const int inum) const;
		std::string printMyClass() const;
		
	protected:
		std::string _Idea[100];
};

#endif