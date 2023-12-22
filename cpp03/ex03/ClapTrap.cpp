/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:12:15 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/22 16:06:01 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor called!" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "A ClapTrap with name " << name << " was constructed!" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & copy) {
	std::cout << "ClapTrap copy constructor called!" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called!" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & copy) {
	std::cout << "ClapTrap copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->name = copy.getName();
		this->hitPoints = copy.getHitPoints();
		this->energyPoints = copy.getEnergyPoints();
		this->attackDamage = copy.getAttackDamage();
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const {
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->attackDamage);
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints == 0 || this->energyPoints == 0) {
			std::cout 	<< "ClapTrap " << this->name << " cannot attack " << target
		<< ", because it either has no energy or hit points!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout 	<< "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > amount) {
		this->hitPoints -= amount;
		std::cout 	<< "ClapTrap " << this->name << " loses " << amount
					<< " hit points!" << std::endl;
	}
	else {
		this->hitPoints = 0;
		std::cout 	<< "ClapTrap " << this->name << " has already lost all hit points!"
					<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		std::cout 	<< "ClapTrap " << this->name << " cannot repair his hit points "
					<< "because energy points are 0!" << std::endl;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout 	<< "ClapTrap " << this->name << " repaired " << amount
				<< " hit points!" << std::endl;
}

