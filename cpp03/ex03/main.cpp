/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/22 18:57:44 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap a("Dardan");
	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
	<< ", Hit Points " << a.getHitPoints()
	<< ", Attack Damage " << a.getAttackDamage()  << "!"
	<< RESET << std::endl;
	a.attack("Dardan");
	a.ClapTrap::attack("Dardan");
	a.beRepaired(0);
	a.takeDamage(0);
	a.whoAmI();
	a.guardGate();
	a.highFivesGuys();
	return (0);
}

