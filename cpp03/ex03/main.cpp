/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/22 11:12:16 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap a("Dardan");
	a.attack("Dardan");
	a.ClapTrap::attack("Dardan");
	a.beRepaired(0);
	a.takeDamage(0);
	a.whoAmI();
	a.guardGate();
	a.highFivesGuys();
	return (0);
}

