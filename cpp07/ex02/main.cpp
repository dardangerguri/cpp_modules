/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/24 15:21:17 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750

int	main(void)
{
	std::cout << GREEN "SUBJECT TESTS" RESET << std::endl;

	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	std::cout << std::endl;

	std::cout << GREEN "MY TESTS" RESET << std::endl;
	try
	{
		std::cout << YELLOW "ARRAYS OF INT" RESET << std::endl;
		Array<int>	a(10);
		Array<int>	b(4);
		Array<int>	c(a);
		Array<int>	d;

		d = b;

		/* FILL ARRAYS */
		for (int i = 0; i < 5; i++)
			a[i] = i + 1;
		for (int i = 0; i < 4; i++)
			b[i] = i + 1;
		for (int i = 0; i < 5; i++)
			c[i] = i + 1;
		for (int i = 0; i < 4; i++)
			d[i] = i + 1;

		std::cout << YELLOW "Using constructor: " RESET << std::endl;
		std::cout << BLUE "Array A: " RESET;
		for (int i = 0; i < 5; i++)
			std::cout << a[i] << " | ";
		std::cout << std::endl;

		std::cout << YELLOW "Using constructor: " RESET << std::endl;
		std::cout << BLUE "Array B: " RESET;
		for (int i = 0; i < 4; i++)
			std::cout << b[i] << " | ";
		std::cout << std::endl;

		std::cout << YELLOW "Using copy constructor (c(a)): " RESET << std::endl;
		std::cout << BLUE "Array C: " RESET;
		for (int i = 0; i < 5; i++)
			std::cout << c[i] << " | ";
		std::cout << std::endl;

		std::cout << YELLOW "Using copy assignement operator (d = b): " RESET << std::endl;
		std::cout << BLUE "Array D: " RESET;
		for (int i = 0; i < 10; i++)
			std::cout << d[i] << " | ";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << YELLOW "ARRAYS OF CHAR" YELLOW << std::endl;
		Array<char>	a(5);
		Array<char>	b(4);
		Array<char>	c(a);
		Array<char>	d;

		d = b;

		/* FILL ARRAYS */
		for (int i = 0; i < 5; i++)
			a[i] = 'A' + i;
		for (int i = 0; i < 4; i++)
			b[i] = 'A' + i;
		for (int i = 0; i < 5; i++)
			c[i] = 'A' + i;
		for (int i = 0; i < 4; i++)
			d[i] = 'A' + i;

		//print array a
		std::cout << YELLOW "Using constructor: " RESET << std::endl;
		std::cout << BLUE "Array A: " RESET;
		for (int i = 0; i < 5; i++)
			std::cout << a[i] << " | ";
		std::cout << std::endl;

		std::cout << YELLOW "Using constructor: " RESET << std::endl;
		std::cout << BLUE "Array B: " RESET;
		for (int i = 0; i < 4; i++)
			std::cout << b[i] << " | ";
		std::cout << std::endl;

		std::cout << YELLOW "Using copy constructor (c(a)): " RESET << std::endl;
		std::cout << BLUE "Array C: " RESET;
		for (int i = 0; i < 5; i++)
			std::cout << c[i] << " | ";
		std::cout << std::endl;

		std::cout << YELLOW "Using copy assignement operator (d = b): " RESET << std::endl;
		std::cout << BLUE "Array D: " RESET;
		for (int i = 0; i < 5; i++)
			std::cout << d[i] << " | ";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
