/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/28 14:00:16 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal default constructor called!" << std::endl;
	this->type = "Unknown AAnimal";
}

AAnimal::AAnimal(AAnimal const & copy) {
	std::cout << "AAnimal copy constructor called!" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called!" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal & copy) {
	std::cout << "AAnimal copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

std::string AAnimal::getType(void) const {
	return (this->type);
}
