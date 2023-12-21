/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/21 16:05:40 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	FragTrap	a("Dardan");

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
	a.highFivesGuys();
	a.highFivesGuys();
	a.highFivesGuys();
	a.highFivesGuys();
	std::cout << RED <<  "Energy Points " << a.getEnergyPoints()
		<< ", Hit Points " << a.getHitPoints()
		<< ", Attack Damage " << a.getAttackDamage()  << "!"
		<< RESET << std::endl;
}

