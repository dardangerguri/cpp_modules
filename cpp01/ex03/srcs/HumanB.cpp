/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:04 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/13 15:14:03 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
}

HumanB::~HumanB(void) {
}

void	HumanB::attack(void) {
	if (this->weapon == NULL)
		std::cout	<< GREEN << this->name << " has no weapon!" << RESET << std::endl;
	else
		std::cout 	<< GREEN << this->name << " attacks with his "
					<< this->weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon  &weapon) {
	this->weapon = &weapon;
}
