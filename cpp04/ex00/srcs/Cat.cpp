/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 18:35:57 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat default constructor called!" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const & copy) {
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = copy;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called!" << std::endl;
}

Cat & Cat::operator=(const Cat & copy) {
	std::cout << "Cat copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << this->type << " says meow meow!" << std::endl;
}
