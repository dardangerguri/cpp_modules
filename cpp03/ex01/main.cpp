/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/21 10:59:14 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a("Dardan");

	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
			<< ", Hit Points " << a.getHitPoints()
			<< ", Attack Damage " << a.getAttackDamage()  << "!"
			<< RESET << std::endl;

	a.attack("Dardan");
	a.attack("Dardan");
	a.attack("Dardan");
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
	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
		<< ", Hit Points " << a.getHitPoints()
		<< ", Attack Damage " << a.getAttackDamage()  << "!"
		<< RESET << std::endl;
}

