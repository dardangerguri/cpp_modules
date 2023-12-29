/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:01:35 by dardangergu       #+#    #+#             */
/*   Updated: 2023/12/29 15:14:14 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {
	std::cout << "Ice default constructor called!" << std::endl;
	this->type = "ice";
}

Ice::Ice(Ice const & copy) {
	std::cout << "Ice copy constructor called!" << std::endl;
	*this = copy;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called!" << std::endl;
}

Ice & Ice::operator=(const Ice & copy) {
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
