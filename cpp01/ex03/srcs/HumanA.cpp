/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:57:54 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/13 15:12:50 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}


HumanA::~HumanA(void) {
}

void	HumanA::attack(void) {
	std::cout 	<< BLUE << this->name << " attacks with his "
				<< this->weapon.getType() << RESET << std::endl;
}
