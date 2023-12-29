/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:58:16 by dardangergu       #+#    #+#             */
/*   Updated: 2023/12/29 02:01:04 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) {
	std::cout << "Cure default constructor called!" << std::endl;
	this->type = "cure";
}

Cure::Cure(Cure const & copy) {
	std::cout << "Cure copy constructor called!" << std::endl;
	*this = copy;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called!" << std::endl;
}

Cure & Cure::operator=(const Cure & copy) {
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}