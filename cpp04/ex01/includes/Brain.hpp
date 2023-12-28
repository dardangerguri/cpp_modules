/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/28 13:08:42 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "Animal.hpp"

class	Brain {

	public:

		Brain(void);
		Brain(Brain const & copy);
		~Brain(void);

		Brain & operator=(const Brain & copy);

		std::string	getIdea(unsigned int i);
		void		setIdea(std::string idea, unsigned int i);

	private:

		std::string ideas[100];
};

# endif
