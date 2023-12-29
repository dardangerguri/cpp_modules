/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/29 15:36:59 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called!" << std::endl;
	this->type = "Unknown Animal";
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "WrongAnimal type constructor called!" << std::endl;
	this->type = type;
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
