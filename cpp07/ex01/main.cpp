/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/22 14:21:17 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {

	std::cout << YELLOW << "Interger Array" << RESET << std::endl;
	int	array[6] = {60, 3, 20, 11, 33, 85};
		std::cout << "Before decrementing: " << std::endl;
		iter(array, 6, ::print);
		std::cout << std::endl;
		std::cout << "After decrementing: " << std::endl;
		iter(array, 6, ::decrement);
		std::cout << std::endl;

		std::cout << YELLOW "String Array" RESET << std::endl;
		std::string	array1[3] = {"Hello! ", "Dardan ", "Doing an evalutation!"};
		iter(array1, 3, ::print);
}