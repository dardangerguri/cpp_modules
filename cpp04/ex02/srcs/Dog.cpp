/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/28 13:33:27 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog default constructor called!" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const & copy) {
	std::cout << "Dog copy constructor called!" << std::endl;
	this->brain = new Brain(*copy.brain);
	*this = copy;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called!" << std::endl;
	delete this->brain;
}

Dog & Dog::operator=(const Dog & copy) {
	std::cout << "Dog copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain();
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << this->type << " says woof woof!" << std::endl;
}

Brain	&Dog::getBrain(void) const {
	return (*this->brain);
}
