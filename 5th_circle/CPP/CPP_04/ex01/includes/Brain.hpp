/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:53:14 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 11:22:22 by mkuida           ###   ########.fr       */
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

		std::string printMyClass() const;
		Brain& operator=(const Brain& other);

		std::string _Idea[100];
		
	private:
};

#endif