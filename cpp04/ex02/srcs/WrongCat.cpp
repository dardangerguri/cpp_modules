/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 18:36:35 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called!" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & copy) {
	std::cout << "WrongCat copy constructor called!" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & copy) {
	std::cout << "WrongCat copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << this->type << " says MEOWWWW!" << std::endl;
}

