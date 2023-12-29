/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 21:10:15 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
	std::cout << "AMateria default constructor called!" << std::endl;
	this->type = "Unknown AMateria";
}

AMateria::AMateria(std::string const & type) {
	std::cout << "AMateria type constructor called!" << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const & copy) {
	std::cout << "AMateria copy constructor called!" << std::endl;
	*this = copy;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called!" << std::endl;
}

AMateria & AMateria::operator=(const AMateria & copy) {
	std::cout << "AMateria copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

std::string const &AMateria::getType(void) const {
	return (this->type);
}

void AMateria::use(ICharacter & target) {
	std::cout << "Unknown Materia used on " << target.getName() << " *" << std::endl;
}
//check this again!