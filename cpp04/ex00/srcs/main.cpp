/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:53 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 21:34:01 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "--------SUBJECT TESTS--------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "--------CORRECT TESTS--------" << std::endl;

	const Animal* a = new Animal();
	std::cout << a->getType() << " " << std::endl;
	a->makeSound();
	delete a;

	const Animal* b = new Dog();
	std::cout << b->getType() << " " << std::endl;
	b->makeSound();
	delete b;

	const Animal* c = new Cat();
	std::cout << c->getType() << " " << std::endl;
	c->makeSound();
	delete c;

	std::cout << std::endl << "--------WRONG TESTS--------" << std::endl;

	const WrongAnimal* d = new WrongAnimal();
	std::cout << d->getType() << " " << std::endl;
	d->makeSound();
	delete d;

	const WrongAnimal* e = new WrongCat();
	std::cout << e->getType() << " " << std::endl;
	e->makeSound();
	delete e;

	return 0;
}
