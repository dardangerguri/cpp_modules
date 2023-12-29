/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 21:10:15 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource default constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy) {
	std::cout << "MateriaSource copy constructor called!" << std::endl;
	*this = copy;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = copy.inventory[i]->clone();
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & copy) {
	std::cout << "MateriaSource copy assignment operator called!" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
			delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			this->inventory[i] = copy.inventory[i]->clone();
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria * m) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "MateriaSource learned " << m->getType() << " materia!" << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource inventory full! Cannot learn the materia!" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type) {
			std::cout << "Materia " << type << " created!" << std::endl;
			return (this->inventory[i]->clone());
		}
	}
	std::cout << "MateriaSource inventory empty! Cannot create the materia!" << std::endl;
	return (NULL);
}
