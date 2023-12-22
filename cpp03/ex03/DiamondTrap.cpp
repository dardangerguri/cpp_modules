/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:12:15 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/21 11:17:27 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap default constructor called!" << std::endl;
	this->hitPoints = FragTrap().getHitPoints();
	this->energyPoints = ScavTrap().getEnergyPoints();
	this->attackDamage = FragTrap().getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {
	std::cout << "A DiamondTrap with name " << this->name << " was constructed!" << std::endl;
	this->hitPoints = FragTrap().getHitPoints();
	this->energyPoints = ScavTrap().getEnergyPoints();
	this->attackDamage = FragTrap().getAttackDamage();
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & copy) {
	std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->name = copy.getName();
		this->hitPoints = copy.getHitPoints();
		this->energyPoints = copy.getEnergyPoints();
		this->attackDamage = copy.getAttackDamage();
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My name is " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}
