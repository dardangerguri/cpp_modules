/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:57:54 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/29 14:28:36 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}


HumanA::~HumanA(void) {
}

void	HumanA::attack(void) {
	std::cout 	<< this->name << " attacks with his " << this->weapon.getType()
				<< std::endl;
}
