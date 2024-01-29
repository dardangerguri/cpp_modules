/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/29 19:55:24 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void	testSubject(void) {
	std::cout << YELLOW "Test Subject" RESET << std::endl;

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void	testInt(void) {
	std::cout << YELLOW "Test Integers" RESET << std::endl << std::endl;

	int a = 4000;
	int b = -4000;

	std::cout << BLUE "Before swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max( a, b ) << ", min = " << ::min( a, b ) << std::endl;
	::swap( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max( a, b ) << ", min = " << ::min( a, b ) << std::endl << std::endl;

	a = std::numeric_limits<int>::max();
	b = std::numeric_limits<int>::min();
	std::cout << BLUE "Before swap: " RESET << std::endl
	<< "a = " << a << ", b = " << b << std::endl
	<< "max = " << ::max( a, b ) << ", min = " << ::min( a, b ) << std::endl;
	::swap( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max( a, b ) << ", min = " << ::min( a, b ) << std::endl;
}

void	testFloat(void) {
	std::cout << YELLOW "Test Float" RESET << std::endl << std::endl;

	float a = 400.55f;
	float b = -400.55f;

	std::cout << BLUE "Before swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<float>( a, b ) << ", min = " << ::min<float>( a, b ) << std::endl;
	::swap<float>( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<float>( a, b ) << ", min = " << ::min<float>( a, b ) << std::endl << std::endl;

	a = std::numeric_limits<float>::max();
	b = std::numeric_limits<float>::min();
	std::cout << BLUE "Before swap: " RESET << std::endl
	<< "a = " << a << ", b = " << b << std::endl
	<< "max = " << ::max<float>( a, b ) << ", min = " << ::min<float>( a, b ) << std::endl;
	::swap<float>( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<float>( a, b ) << ", min = " << ::min<float>( a, b ) << std::endl;
}

void	testChar(void) {
	std::cout << YELLOW "Test Char" RESET << std::endl << std::endl;

	char a = 'a';
	char b = 'h';

	std::cout << BLUE "Before swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<char>( a, b ) << ", min = " << ::min<char>( a, b ) << std::endl;
	::swap<char>( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<char>( a, b ) << ", min = " << ::min<char>( a, b ) << std::endl << std::endl;

	a = 42;
	b = 113;
	std::cout << BLUE "Before swap: " RESET << std::endl
	<< "a = " << a << ", b = " << b << std::endl
	<< "max = " << ::max<char>( a, b ) << ", min = " << ::min<char>( a, b ) << std::endl;
	::swap<char>( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<char>( a, b ) << ", min = " << ::min<char>( a, b ) << std::endl;
}

void	testString(void) {
	std::cout << YELLOW "Test String" RESET << std::endl << std::endl;

	std::string a = "hello";
	std::string b = "world";

	std::cout << BLUE "Before swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<std::string>( a, b ) << ", min = " << ::min<std::string>( a, b ) << std::endl;
	::swap<std::string>( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<std::string>( a, b ) << ", min = " << ::min<std::string>( a, b ) << std::endl << std::endl;

	a = "HELLO";
	b = "aaaaaa";
	std::cout << BLUE "Before swap: " RESET << std::endl
	<< "a = " << a << ", b = " << b << std::endl
	<< "max = " << ::max<std::string>( a, b ) << ", min = " << ::min<std::string>( a, b ) << std::endl;
	::swap<std::string>( a, b );
	std::cout << GREEN "After swap: " RESET << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "max = " << ::max<std::string>( a, b ) << ", min = " << ::min<std::string>( a, b ) << std::endl;
}

int main( void ) {
	testSubject();
	std::cout << std::endl;
	testInt();
	std::cout << std::endl;
	testFloat();
	std::cout << std::endl;
	testChar();
	std::cout << std::endl;
	testString();
	return 0;
}
