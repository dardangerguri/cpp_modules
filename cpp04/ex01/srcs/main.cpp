/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:53 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/28 13:42:19 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	std::cout << "--------SUBJECT TESTS--------" << std::endl;

	const Animal* j = new Dog();
	delete j;
	const Animal* i = new Cat();
	delete i;

	std::cout << std::endl << "--------TESTS--------" << std::endl;

	Dog *dog = new Dog();
	dog->getBrain().setIdea("IDEA", 3);
	dog->getBrain().setIdea("NO IDEA", 101);

	Dog temporary = *dog;
	std::cout << temporary.getType() << std::endl;
	std::cout << dog->getBrain().getIdea(1) <<  std::endl;
	std::cout << temporary.getBrain().getIdea(2) <<  std::endl;

	Cat *cat = new Cat();
	cat->getBrain().setIdea("IDEA", 3);
	cat->getBrain().setIdea("NO IDEA", 101);
	std::cout << cat->getBrain().getIdea(3) << std::endl;

	delete dog;
	delete cat;
	return 0;
}
