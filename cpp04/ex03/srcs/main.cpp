/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:16:26 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/05 15:40:42 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

void subjectTest() {
	std::cout << GREEN "---------Subject test---------" RESET << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;
}

void materiaSourceTest() {
	std::cout << std::endl << GREEN "---------MateriaSource test---------" RESET << std::endl;

	std::cout << YELLOW "Create MateriaSource" RESET << std::endl;
		MateriaSource * s = new MateriaSource();
		s->displayInventory();

	std::cout << std::endl << YELLOW "Learn Materia" RESET << std::endl;
		s->learnMateria(NULL);
		s->learnMateria(new Cure());
		s->learnMateria(new Ice());
		s->displayInventory();

	std::cout << std::endl << YELLOW "Deep Copy MateriaSource" RESET << std::endl;
		MateriaSource * copyS = new MateriaSource(*s);
		std::cout << "Original ";
		s->displayInventory();
		std::cout << "Copy ";
		copyS->displayInventory();
		s->learnMateria(new Ice());
		std::cout << "Original ";
		s->displayInventory();
		std::cout << "Copy ";
		copyS->displayInventory();
		delete copyS;

	std::cout << std::endl << YELLOW "Learn Plenty Materia" RESET << std::endl;
		s->learnMateria(new Ice());
		s->learnMateria(new Ice());
		s->learnMateria(new Ice());
		s->displayInventory();

	std::cout << std::endl << YELLOW "Create Materia" RESET << std::endl;
		AMateria* tmp;
		tmp = s->createMateria("ice");
		if (tmp != NULL)
			delete tmp;
		AMateria* tmp1;
		tmp1 = s->createMateria("cure");
		if (tmp1 != NULL)
			delete tmp1;
		AMateria* tmp2;
		tmp2 = s->createMateria("unknown");
		if (tmp2 != NULL)
			delete tmp2;

	delete s;
}

void characterTest() {
	std::cout << std::endl << GREEN "---------Character test---------" RESET << std::endl;

	std::cout << YELLOW "Create Materia" RESET << std::endl;
		AMateria *	materia1 = new Cure();
		AMateria *	materia2 = new Ice();

	std::cout << std::endl << YELLOW "Create Character" RESET << std::endl;
		Character *	d = new Character("Dardan");
		d->displayCharacterInventory();

	std::cout << std::endl << YELLOW "Equip Character" RESET << std::endl;
		d->equip(NULL);
		d->equip(materia1);
		d->equip(materia2);
		d->displayCharacterInventory();

	std::cout << std::endl << YELLOW "Deep Copy Character" RESET << std::endl;
		Character * copyD = new Character(*d);
		std::cout << "Original ";
		d->displayCharacterInventory();
		std::cout << "Copy ";
		copyD->displayCharacterInventory();
		d->equip(materia2);
		std::cout << "Original ";
		d->displayCharacterInventory();
		std::cout << "Copy ";
		copyD->displayCharacterInventory();
		delete copyD;

	std::cout << std::endl << YELLOW "Character Equipping Plenty Items" RESET << std::endl;
		d->equip(materia1);
		d->equip(materia2);
		d->equip(materia1);
		d->displayCharacterInventory();

	std::cout << std::endl << YELLOW "Character Unequipping Items" RESET << std::endl;
		d->unequip(0);
		d->unequip(-20);
		d->unequip(1);
		d->unequip(2);
		d->unequip(3);
		d->unequip(3);
		d->unequip(4);
		d->displayCharacterInventory();

	delete d;
}

int main() {
	subjectTest();
	materiaSourceTest();
	characterTest();
}

