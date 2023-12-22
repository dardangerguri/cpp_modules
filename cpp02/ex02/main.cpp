/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/22 12:38:51 by dgerguri         ###   ########.fr       */
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
	Fixed n1(5);
	Fixed n2(10);
	std::cout << n1 << " > " << n2 << " = " << (n1 > n2) << std::endl;
	std::cout << n1 << " < " << n2 << " = " << (n1 < n2) << std::endl;
	std::cout << n1 << " >= " << n2 << " = " << (n1 >= n2) << std::endl;
	std::cout << n1 << " <= " << n2 << " = " << (n1 <= n2) << std::endl;
	std::cout << n1 << " == " << n2 << " = " << (n1 == n2) << std::endl;
	std::cout << n1 << " != " << n2 << " = " << (n1 != n2) << std::endl << std::endl;

	std::cout << RED << "Arithmetic operators tests" << RESET << std::endl;
	Fixed	nbr1(20);
	Fixed	nbr2(2);
	std::cout << nbr1 << " + " << nbr2 << " = " << nbr1 + nbr2 << std::endl;
	std::cout << nbr1 << " - " << nbr2 << " = " << nbr1 - nbr2 << std::endl;
	std::cout << nbr1 << " * " << nbr2 << " = " << nbr1 * nbr2 << std::endl;
	std::cout << nbr1 << " / " << nbr2 << " = " << nbr1 / nbr2 << std::endl << std::endl;

	std::cout << BLUE << "Min and Max tests" << RESET << std::endl;
	Fixed	nb1(5);
	Fixed	nb2(10);
	std::cout << "Min(" << nb1 << ", " << nb2 << ") = " << Fixed::min(nb1, nb2) << std::endl;
	std::cout << "Max(" << nb1 << ", " << nb2 << ") = " << Fixed::max(nb1, nb2) << std::endl;
	std::cout << "Min(" << nb1 << ", " << nb2 << ") = " << Fixed::min(nb1, nb2) << std::endl;
	std::cout << "Max(" << nb1 << ", " << nb2 << ") = " << Fixed::max(nb1, nb2) << std::endl << std::endl;

	std::cout << GREEN << "Increment/Decrement operators tests" << RESET << std::endl;
	Fixed	number(5);
	std::cout << "++" << number << " = " << ++number << std::endl;
	std::cout << number << "++ = " << number++ << std::endl;
	std::cout << "--" << number << " = " << --number << std::endl;
	std::cout << number << "-- = " << number-- << std::endl << std::endl;

	return 0;
}

