/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:01:35 by dardangergu       #+#    #+#             */
/*   Updated: 2024/02/05 14:39:07 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {
	std::cout << BLUE "Ice default constructor called!" RESET << std::endl;
	this->type = "ice";
}

Ice::Ice(Ice const & copy) {
	std::cout << BLUE "Ice copy constructor called!" RESET << std::endl;
	*this = copy;
}

Ice::~Ice(void) {
	std::cout << BLUE "Ice destructor called!" RESET << std::endl;
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
