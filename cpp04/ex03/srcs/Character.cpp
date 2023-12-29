/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/29 18:34:23 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
	std::cout << "Character default constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = "Default";
}

Character::Character(std::string const & name) {
	std::cout << "Character name constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = name;
}

Character::Character(Character const & copy) {
	std::cout << "Character copy constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = copy.inventory[i]->clone();
	*this = copy;
}

Character::~Character(void) {
	std::cout << "Character destructor called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
		{
			std::cout << "deleting " << i << std::endl;
			delete this->inventory[i];
			std::cout << "deleted " << i << std::endl;
		}
	}
}

Character & Character::operator=(const Character & copy) {
	std::cout << "Character assignation operator called!" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
			delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			this->inventory[i] = copy.inventory[i]->clone();
	}
	return (*this);
}

void		Character::setName(std::string const & name) {
	this->name = name;
}

std::string const & Character::getName(void) const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Error: materia doesn't exist!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << getName() << " equiped with materia " << this->inventory[i]->getType()
				<< "!" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full, cannot equip!" << std::endl;
	delete m;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		std::cout << "Index out of range!" << std::endl;
	else if (!this->inventory[idx])
		std::cout << "Materia doesn't exist!" << std::endl;
	else {
		std::cout << "Materia " << this->inventory[idx]->getType() << " unequiped!" << std::endl;
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4)
		std::cout << "Index out of range!" << std::endl;
	else if (this->inventory[idx]) {
		std::cout << "Materia " << this->inventory[idx]->getType() << " used!" << std::endl;
		this->inventory[idx]->use(target);
	}
	else
		std::cout << "There is nothing in the inventory" << std::endl;

}

AMateria* Character::getInventory(int idx) {
	if (idx >= 0 || idx <= 4) {
		std::cout << RED << "INVENTORY " << &this->inventory[idx] << RESET << std::endl;
			return (this->inventory[idx]);
	}
	return (NULL);
}
