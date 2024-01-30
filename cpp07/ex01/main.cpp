/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/30 16:05:40 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {

	/* Integer Array */
	std::cout << RED "Integer Array" RESET << std::endl;

	int array_int[6] = {40, 3, 51, 94, 33, 85};

	std::cout << BLUE "  Array" RESET << std::endl;
	iter(array_int, 6, ::print);
	std::cout <<std::endl << BLUE "  Array after decrementation: " RESET << std::endl;
	iter(array_int, 6, ::decrement);
	iter(array_int, 6, ::print);

	/* Double Array */
	std::cout << std::endl << std::endl << RED "Double Array" RESET << std::endl;

	double array_double[6] = {40.4, 3.4, 51.2, 94.3, 33.7, 85.2};

	std::cout << BLUE "  Array" RESET << std::endl;
	iter(array_double, 6, ::print);
	std::cout <<std::endl << BLUE "  Array after decrementation: " RESET << std::endl;
	iter(array_double, 6, ::decrement);
	iter(array_double, 6, ::print);

	/* Char Array */
	std::cout << std::endl << std::endl << RED "Char Array" RESET << std::endl;

	char array_char[6] = {'l', 'b', 'c', 'd', 'e', 'f'};

	std::cout << BLUE "  Array" RESET << std::endl;
	iter(array_char, 6, ::print);
	std::cout <<std::endl << BLUE "  Array after decrementation: " RESET << std::endl;
	iter(array_char, 6, ::decrement);
	iter(array_char, 6, ::print);
	std::cout <<std::endl << BLUE "  Array after capitalization: " RESET << std::endl;
	iter(array_char, 6, ::capitalize);
	iter(array_char, 6, ::print);

	/* String Array */
	std::cout << std::endl << std::endl << RED "String Array" RESET << std::endl;

	std::string array_string[6] = {"dd", "aa", "cc", "dd", "ff", "mm"};

	std::cout << BLUE "  Array" RESET << std::endl;
	iter(array_string, 6, ::print);
	std::cout <<std::endl << BLUE "  Array after capitalization: " RESET << std::endl;
	iter(array_string, 6, ::capitalizeString);
	iter(array_string, 6, ::print);

	return 0;
}
