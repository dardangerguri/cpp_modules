/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/28 14:29:16 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = "Default";
}

Character::Character(std::string const & name) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = name;
}

Character::Character(Character const & copy) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = copy;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
}

Character & Character::operator=(const Character & copy) {
	if (this != &copy) {
		this->name = copy.name;
		for (int i = 0; i < 4; i++)
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			this->inventory[i] = copy.inventory[i]->clone();
	}
	return (*this);
}

void Character::setName(std::string const & name) {
	this->name = name;
}

std::string const & Character::getName(void) const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			return ;
		}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}



