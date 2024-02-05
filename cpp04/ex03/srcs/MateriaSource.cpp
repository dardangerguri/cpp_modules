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
	std::cout << BLUE "MateriaSource default constructor called!" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy) {
	std::cout << BLUE "MateriaSource copy constructor called!" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = copy;
}

MateriaSource::~MateriaSource(void) {
	std::cout << BLUE "MateriaSource destructor called!" RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & copy) {
	std::cout << BLUE "MateriaSource copy assignment operator called!" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	for (int i = 0; i < 4; i++) {
		if (copy.inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i]->clone();
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria * m) {
	if (!m) {
		std::cout << "MateriaSource was not provided with a materia to learn!" << std::endl;
		return ;
	}
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
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type) {
			std::cout << "Materia " << type << " created!" << std::endl;
			return (this->inventory[i]->clone());
		}
	}
	std::cout << "Unknown type! Cannot create the materia!" << std::endl;
	return (NULL);
}

void	MateriaSource::displayInventory(void)
{
	std::cout << "MateriaSource has the following inventory: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->inventory[i] == NULL)
			std::cout << "Empty!";
		else
			std::cout << this->inventory[i]->getType() << " materia.";
		std::cout << std::endl;
	}
}
