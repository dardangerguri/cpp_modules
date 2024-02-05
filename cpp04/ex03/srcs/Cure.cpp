/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:58:16 by dardangergu       #+#    #+#             */
/*   Updated: 2024/02/05 14:39:57 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) {
	std::cout << BLUE "Cure default constructor called!" RESET << std::endl;
	this->type = "cure";
}

Cure::Cure(Cure const & copy) {
	std::cout << BLUE "Cure copy constructor called!" RESET << std::endl;
	*this = copy;
}

Cure::~Cure(void) {
	std::cout << BLUE "Cure destructor called!" RESET << std::endl;
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
