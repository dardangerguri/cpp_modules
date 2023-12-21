/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/21 15:47:39 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	a("Dardan");

	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
			<< ", Hit Points " << a.getHitPoints()
			<< ", Attack Damage " << a.getAttackDamage()  << "!"
			<< RESET << std::endl;

	a.attack("Dardan");
	a.attack("Dardan");
	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
			<< ", Hit Points " << a.getHitPoints()
			<< ", Attack Damage " << a.getAttackDamage()  << "!"
			<< RESET << std::endl;
	a.takeDamage(5);
	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
			<< ", Hit Points " << a.getHitPoints()
			<< ", Attack Damage " << a.getAttackDamage()  << "!"
			<< RESET << std::endl;
	a.beRepaired(10);
	a.guardGate();
	a.guardGate();
	a.guardGate();
	a.guardGate();
	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
		<< ", Hit Points " << a.getHitPoints()
		<< ", Attack Damage " << a.getAttackDamage()  << "!"
		<< RESET << std::endl;
}

