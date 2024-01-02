/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:53 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/02 15:44:08 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// int main() {
// 	std::cout << "--------SUBJECT TESTS--------" << std::endl;

// 	const Animal* j = new Dog();
// 	delete j;
// 	const Animal* i = new Cat();
// 	delete i;

// 	std::cout << std::endl << "--------TESTS--------" << std::endl;

// 	Dog *dog = new Dog();
// 	dog->getBrain().setIdea("IDEA", 3);
// 	dog->getBrain().setIdea("NO IDEA", 101);

// 	Dog temporary = *dog;
// 	std::cout << temporary.getType() << std::endl;
// 	std::cout << dog->getBrain().getIdea(1) <<  std::endl;
// 	std::cout << temporary.getBrain().getIdea(2) <<  std::endl;

// 	Cat *cat = new Cat();
// 	cat->getBrain().setIdea("IDEA", 3);
// 	cat->getBrain().setIdea("NO IDEA", 101);
// 	std::cout << cat->getBrain().getIdea(3) << std::endl;

// 	delete dog;
// 	delete cat;
// 	return 0;
// }

void	arrayTest(void)
{
	std::cout	<< "--- ANIMAL ARRAY TEST ---" << std::endl << std::endl;

	Animal *	animalArray[4 + 1];
	animalArray[4] = NULL;

	std::cout	<< "Creating an array of animals consisting of:" << std::endl
				<< 4 / 2 << " cats" << std::endl
				<< 4 / 2 << " dogs" << std::endl;
	for (int i = 0; i < 4 / 2; i++)
		animalArray[i] = new Cat();
	std::cout << std::endl;
	for (int i = 4 / 2; i < 4; i++)
		animalArray[i] = new Dog();
	std::cout << std::endl << "The animals make some sound" << std::endl;
	for (int i = 0; i < 4; i++)
		animalArray[i]->makeSound();
	std::cout << std::endl << "Destroying the array" << std::endl;
	for (int i = 0; animalArray[i]; i++)
		delete animalArray[i];
	std::cout << std::endl;
}

void	catBrainTest(void)
{
	std::cout << "--- CAT BRAIN TEST ---" << std::endl << std::endl;

	std::cout << "Creating a cat" << std::endl;
	Cat *	cat = new Cat();

	std::cout << "Putting ideas in it's head" << std::endl;
	cat->getBrain().setIdea("I am the ruler of this kindom", 0);
	cat->getBrain().setIdea("These so called humans are my loyal servants", 1);
	cat->getBrain().setIdea("I'm hungry", 2);

	std::cout << "Cat idea 0: " << cat->getBrain().getIdea(0) << std::endl;
	std::cout << "Cat idea 1: " << cat->getBrain().getIdea(1) << std::endl;
	std::cout << "Cat idea 2: " << cat->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "Creating a copy of our cat" << std::endl;
	Cat *	copyCat = new Cat(*cat);

	std::cout << std::endl << "copyCat should have the same thoughts in it's brain" << std::endl;
	std::cout << "copyCat idea 0: " << copyCat->getBrain().getIdea(0) << std::endl;
	std::cout << "copyCat idea 1: " << copyCat->getBrain().getIdea(1) << std::endl;
	std::cout << "copyCat idea 2: " << copyCat->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "lets put some new ideas to our original cats brain" << std::endl;
	cat->getBrain().setIdea("I want to go outside and hunt", 0);
	cat->getBrain().setIdea("I am a master hunter", 1);
	cat->getBrain().setIdea("damn, im still hungry", 2);

	std::cout << "Cat idea 0: " << cat->getBrain().getIdea(0) << std::endl;
	std::cout << "Cat idea 1: " << cat->getBrain().getIdea(1) << std::endl;
	std::cout << "Cat idea 2: " << cat->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "copyCat's brain should not have been altered" << std::endl;
	std::cout << "copyCat idea 0: " << copyCat->getBrain().getIdea(0) << std::endl;
	std::cout << "copyCat idea 1: " << copyCat->getBrain().getIdea(1) << std::endl;
	std::cout << "copyCat idea 2: " << copyCat->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "lets try if my operator overload works as well" << std::endl;
	*copyCat = *cat;

	std::cout << std::endl << "copyCats ideas should now equal to the other cats" << std::endl;
	std::cout << "copyCat idea 0: " << copyCat->getBrain().getIdea(0) << std::endl;
	std::cout << "copyCat idea 1: " << copyCat->getBrain().getIdea(1) << std::endl;
	std::cout << "copyCat idea 2: " << copyCat->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "Destroying cat and copyCat" << std::endl;
	delete cat;
	delete copyCat;
	std::cout << std::endl;
}

void	dogBrainTest(void)
{
	std::cout << "--- DOG BRAIN TEST ---" << std::endl << std::endl;

	std::cout << "Creating a dog" << std::endl;
	Dog *	dog = new Dog();

	std::cout << "Putting ideas in it's head" << std::endl;
	dog->getBrain().setIdea("I'm extremely happy that my owner loves me so much", 0);
	dog->getBrain().setIdea("My owner is my best friend", 1);
	dog->getBrain().setIdea("I really could go for a steak right now", 2);

	std::cout << "Dog idea 0: " << dog->getBrain().getIdea(0) << std::endl;
	std::cout << "Dog idea 1: " << dog->getBrain().getIdea(1) << std::endl;
	std::cout << "Dog idea 2: " << dog->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "Creating a copy of our dog" << std::endl;
	Dog *	copyDog = new Dog(*dog);

	std::cout << std::endl << "copyDog should have the same thoughts in it's brain" << std::endl;
	std::cout << "copyDog idea 0: " << copyDog->getBrain().getIdea(0) << std::endl;
	std::cout << "copyDog idea 1: " << copyDog->getBrain().getIdea(1) << std::endl;
	std::cout << "copyDog idea 2: " << copyDog->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "lets put some new ideas to our original dogs brain" << std::endl;
	dog->getBrain().setIdea("I want to go outside and play", 0);
	dog->getBrain().setIdea("Fetch is one of my favorite games", 1);
	dog->getBrain().setIdea("Chicken would be nice too", 2);

	std::cout << "Dog idea 0: " << dog->getBrain().getIdea(0) << std::endl;
	std::cout << "Dog idea 1: " << dog->getBrain().getIdea(1) << std::endl;
	std::cout << "Dog idea 2: " << dog->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "copyDog's brain should not have been altered" << std::endl;
	std::cout << "copyDog idea 0: " << copyDog->getBrain().getIdea(0) << std::endl;
	std::cout << "copyDog idea 1: " << copyDog->getBrain().getIdea(1) << std::endl;
	std::cout << "copyDog idea 2: " << copyDog->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "lets try if my operator overload works as well" << std::endl;
	*copyDog = *dog;

	std::cout << std::endl << "copyDogs ideas should now equal to the other dogs" << std::endl;
	std::cout << "copyDog idea 0: " << copyDog->getBrain().getIdea(0) << std::endl;
	std::cout << "copyDog idea 1: " << copyDog->getBrain().getIdea(1) << std::endl;
	std::cout << "copyDog idea 2: " << copyDog->getBrain().getIdea(2) << std::endl;

	std::cout << std::endl << "Destroying dog and copyDog" << std::endl;
	delete dog;
	delete copyDog;
	std::cout << std::endl;
}

void	shitsAndGiggles(void)
{
	std::cout << "Creating a new dog and cat" << std::endl;
	Dog *	dog = new Dog();
	Cat *	cat = new Cat();
	std::string	catThought = "Meow!";
	std::string	dogThought = "Woof!";

	std::cout << std::endl << "Filling their heads with ideas" << std::endl;
	for (int i = 0; i < 100; i++)
		dog->getBrain().setIdea(dogThought, i);
	for (int i = 0; i < 100; i++)
		cat->getBrain().setIdea(catThought, i);
	dog->getBrain().setIdea("Meow!", 0);
	dog->getBrain().setIdea("No that sounds wrong...", 1);

	std::cout << std::endl << "Let's see what they think..." << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << "Dog idea " << i << ": " << dog->getBrain().getIdea(i) << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << "Cat idea " << i << ": " << cat->getBrain().getIdea(i) << std::endl;

	std::cout << std::endl << "Alright I think thats enough :)" << std::endl;
	delete dog;
	delete cat;
	std::cout << std::endl;
}

int	main(void)
{
	arrayTest();
	catBrainTest();
	dogBrainTest();
	shitsAndGiggles();

	std::cout << "Testing for deep/shallow copy" << std::endl << std::endl;
	Dog basic;
	{
		Dog tmp = basic; // should create a new brain as this is a deep copy
	}
	std::cout << std::endl << std::endl;

	return (0);
}
