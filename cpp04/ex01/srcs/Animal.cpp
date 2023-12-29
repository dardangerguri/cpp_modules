/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/29 15:36:23 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called!" << std::endl;
	this->type = "Unknown Animal";
}

Animal::Animal(std::string type) {
	std::cout << "Animal type constructor called!" << std::endl;
	this->type = type;
}

Animal::Animal(Animal const & copy) {
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = copy;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called!" << std::endl;
}

Animal & Animal::operator=(const Animal & copy) {
	std::cout << "Animal copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

void Animal::makeSound(void) const {
	std::cout << this->type << " makes sound!" << std::endl;
}

std::string Animal::getType(void) const {
	return (this->type);
}
