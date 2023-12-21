/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:12:15 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/21 15:47:30 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constructor called!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "A ScavTrap with name " << name << " was constructed!" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & copy) {
	std::cout << "ScavTrap copy constructor called!" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called!" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & copy) {
	std::cout << "ScavTrap copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->name = copy.getName();
		this->hitPoints = copy.getHitPoints();
		this->energyPoints = copy.getEnergyPoints();
		this->attackDamage = copy.getAttackDamage();
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoints == 0 || this->energyPoints == 0) {
			std::cout 	<< "ScavTrap " << this->name << " cannot attack " << target
		<< ", because it either has no energy or hit points!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout 	<< "ScavTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode." << std::endl;
}

