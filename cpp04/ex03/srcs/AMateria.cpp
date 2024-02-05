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
	std::cout << BLUE "AMateria default constructor called!" RESET << std::endl;
	this->type = "Unknown AMateria";
}

AMateria::AMateria(std::string const & type) {
	std::cout << BLUE "AMateria type constructor called!" RESET << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const & copy) {
	std::cout << BLUE "AMateria copy constructor called!" RESET << std::endl;
	*this = copy;
}

AMateria::~AMateria(void) {
	std::cout << BLUE "AMateria destructor called!" RESET << std::endl;
}

AMateria & AMateria::operator=(const AMateria & copy) {
	std::cout << BLUE "AMateria copy assignment operator called!" RESET << std::endl;
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
