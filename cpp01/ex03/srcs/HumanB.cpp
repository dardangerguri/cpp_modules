/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:04 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/29 14:33:13 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
}

HumanB::~HumanB(void) {
}

void	HumanB::attack(void) {
	std::cout 	<< this->name << " attacks with his " << this->weapon->getType()
				<< std::endl;
}

void	HumanB::setWeapon(Weapon  &weapon) {
	this->weapon = &weapon;
}
