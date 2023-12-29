/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:16:26 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/29 18:34:35 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main()
{
	std::cout << "---------Subject test---------" << std::endl;

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

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "---------My test---------" << std::endl;

	std::cout << YELLOW << "Let's create a MateriaSource and learn some materia!"
				<< RESET << std::endl << std::endl;
	IMateriaSource* test = new MateriaSource();

    test->learnMateria(new Cure());
    test->learnMateria(new Ice());
    test->learnMateria(new Ice());
    test->learnMateria(new Cure());

	std::cout << RED << "The stock should be full now!" << RESET << std::endl;
	// test->learnMateria(new Cure());
	// test->learnMateria(new Ice());

    // AMateria* temp = new Ice();
    // test->learnMateria(temp);
	// delete (temp);
	std::cout << std::endl;

	std::cout << YELLOW << "Let's create a Character and equip some materia!"
				<< RESET << std::endl << std::endl;
    ICharacter* a = new Character("a");
    ICharacter* b = new Character("b");

    AMateria* cure = test->createMateria("cure");

    a->equip(cure);
    a->equip(test->createMateria("ice"));
    a->equip(test->createMateria("cure"));
    a->equip(test->createMateria("ice"));

	a->equip(test->createMateria("ice"));

	Character *d = new Character("d");
	AMateria *dlt = d->getInventory(1);
	std::cout << RED << "INVENTORY " << dlt << RESET << std::endl;
    a->unequip(1);
    // a->equip(temp);
	delete dlt;
	std::cout << std::endl;

	std::cout << YELLOW << "Let's use some materia!" << RESET << std::endl << std::endl;

    a->use(4, *b);
    a->use(3, *b);
    a->use(2, *b);

    b->use(-1, *a);
	b->use(0, *a);
	b->use(1, *a);
	std::cout << std::endl;

    delete test;
	delete a;
	delete b;
	return 0;
}
