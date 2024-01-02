/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:53 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/02 15:24:28 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main() {
// 	std::cout << "--------SUBJECT TESTS--------" << std::endl;

// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;

// 	std::cout << std::endl << "--------CORRECT TESTS--------" << std::endl;

// 	const Animal* a = new Animal();
// 	std::cout << a->getType() << " " << std::endl;
// 	a->makeSound();
// 	delete a;

// 	const Animal* b = new Dog();
// 	std::cout << b->getType() << " " << std::endl;
// 	b->makeSound();
// 	delete b;

// 	const Animal* c = new Cat();
// 	std::cout << c->getType() << " " << std::endl;
// 	c->makeSound();
// 	delete c;

// 	std::cout << std::endl << "--------WRONG TESTS--------" << std::endl;

// 	const WrongAnimal* d = new WrongAnimal();
// 	std::cout << d->getType() << " " << std::endl;
// 	d->makeSound();
// 	delete d;

// 	const WrongAnimal* e = new WrongCat();
// 	std::cout << e->getType() << " " << std::endl;
// 	e->makeSound();
// 	delete e;

// 	return 0;
// }

int	main(void)
{
	const Animal*		meta = new Animal();
	const Animal*		dog = new Dog();
	const Animal*		cat = new Cat();
	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << std::endl << "type of dog: " << dog->getType() << " " << std::endl;
	std::cout << "type of cat: " << cat->getType() << " " << std::endl;
	std::cout << "type of meta: " << meta->getType() << " " << std::endl;
	std::cout << std::endl << std::endl << "let's make some sound" << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "type of wrongCat: " << wrongCat->getType() << " " << std::endl;
	std::cout << "type of wrongMeta: " << wrongMeta->getType() << " " << std::endl;
	std::cout << std::endl << std::endl << "let's make some sound" << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << std::endl << std::endl << "let's test the wrong cat as a wrong cat now.." << std::endl;
	const WrongCat*	wrongCat2 = new WrongCat();
	std::cout << "type of wrongCat2: " << wrongCat2->getType() << " " << std::endl;
	std::cout << std::endl << std::endl << "let's make some sound" << std::endl;
	wrongCat2->makeSound();
	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
	delete wrongMeta;
	delete wrongCat;

	return (0);
}
