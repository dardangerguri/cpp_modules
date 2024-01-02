/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 21:10:15 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::Brain(Brain const & copy) {
	std::cout << "Brain copy constructor called!" << std::endl;
	*this = copy;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called!" << std::endl;
}

Brain & Brain::operator=(const Brain & copy) {
	std::cout << "Brain copy assignment operator called!" << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea(unsigned int i) {
	if (i <= 100)
		return (this->ideas[i]);
	else {
		return ("Error: No idea is available!");
	}
}

void	Brain::setIdea(std::string idea, unsigned int i) {
	if (i <= 100)
		this->ideas[i] = idea;
	else
		std::cout << "Error: Brain is full!" << std::endl;
}
