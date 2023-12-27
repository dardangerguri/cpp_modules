/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 21:10:21 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called!" << std::endl;
	this->type = "Unknown Animal";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal type constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & copy) {
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & copy) {
	std::cout << "WrongAnimal copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << this->type << " makes an unknown sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}
