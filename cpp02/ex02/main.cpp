/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/22 11:05:55 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	std::cout << RED << "Subject tests" << RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::cout << YELLOW << "Comparison operators tests" << RESET << std::endl;
	std::cout << Fixed(5) << " > " << Fixed(10) << " = " << (Fixed(5) > Fixed(10)) << std::endl;
	std::cout << Fixed(5) << " < " << Fixed(10) << " = " << (Fixed(5) < Fixed(10)) << std::endl;
	std::cout << Fixed(5) << " >= " << Fixed(10) << " = " << (Fixed(5) >= Fixed(10)) << std::endl;
	std::cout << Fixed(5) << " <= " << Fixed(10) << " = " << (Fixed(5) <= Fixed(10)) << std::endl;
	std::cout << Fixed(5) << " == " << Fixed(10) << " = " << (Fixed(5) == Fixed(10)) << std::endl;
	std::cout << Fixed(5) << " != " << Fixed(10) << " = " << (Fixed(5) != Fixed(10)) << std::endl << std::endl;

	std::cout << RED << "Arithmetic operators tests" << RESET << std::endl;
	std::cout << Fixed(5) << " + " << Fixed(5) << " = " << (Fixed(5) + Fixed(5)) << std::endl;
	std::cout << Fixed(5) << " - " << Fixed(5) << " = " << (Fixed(5) - Fixed(5)) << std::endl;
	std::cout << Fixed(5) << " * " << Fixed(5) << " = " << (Fixed(5) * Fixed(5)) << std::endl;
	std::cout << Fixed(5) << " / " << Fixed(5) << " = " << (Fixed(5) / Fixed(5)) << std::endl << std::endl;

	std::cout << BLUE << "Min and Max tests" << RESET << std::endl;
	std::cout << "Min(" << Fixed(5) << ", " << Fixed(10) << ") = " << Fixed::min(Fixed(5), Fixed(10)) << std::endl;
	std::cout << "Max(" << Fixed(5) << ", " << Fixed(10) << ") = " << Fixed::max(Fixed(5), Fixed(10)) << std::endl;
	std::cout << "Min(" << Fixed(5) << ", " << Fixed(10) << ") = " << Fixed::min(Fixed(5), Fixed(10)) << std::endl;
	std::cout << "Max(" << Fixed(5) << ", " << Fixed(10) << ") = " << Fixed::max(Fixed(5), Fixed(10)) << std::endl << std::endl;

	std::cout << GREEN << "Increment/Decrement operators tests" << RESET << std::endl;
	std::cout << "++" << Fixed(5) << " = " << ++Fixed(5) << std::endl;
	std::cout << Fixed(5) << "++ = " << Fixed(5)++ << std::endl;
	std::cout << "--" << Fixed(5) << " = " << --Fixed(5) << std::endl;
	std::cout << Fixed(5) << "-- = " << Fixed(5)-- << std::endl << std::endl;

	return 0;
}

