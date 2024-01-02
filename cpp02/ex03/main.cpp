/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/02 15:15:43 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test1() {
	Point const a(-2, 2);
	Point const b(1, 2);
	Point const c(0, 0);
	Point const p(0, 1);
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "IT IS INSIDE!" << RESET << std::endl;
	else
		std::cout << RED << "IT IS NOT INSIDE!" << RESET << std::endl;
}

void test2() {
	Point const a(0, 0);
	Point const b(0, 4);
	Point const c(4, 0);
	Point const p(0, 4);
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "IT IS INSIDE!" << RESET << std::endl;
	else
		std::cout << RED << "IT IS NOT INSIDE!" << RESET << std::endl;
}

void test3Float() {
	Point const a(-0.55f, 1.37f);
	Point const b(0.25f, 1.11f);
	Point const c(0.25f, -0.47f);
	Point const p(-0.11f, 0.77f);
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "IT IS INSIDE!" << RESET << std::endl;
	else
		std::cout << RED << "IT IS NOT INSIDE!" << RESET << std::endl;
}

void test4Float() {
	Point const a(-0.27f, 1.37f);
	Point const b(0.25f, 1.11f);
	Point const c(0.25f, -0.47f);
	Point const p(0.5f, 2.5f);
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "IT IS INSIDE!" << RESET << std::endl;
	else
		std::cout << RED << "IT IS NOT INSIDE!" << RESET << std::endl;
}

void test5Float() {
	Point const a(2.68f, -2.35f);
	Point const b(8.32f, -3.63f);
	Point const c(4.82f, -3.83f);
	Point const p(4.44f, -3.33f);
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "IT IS INSIDE!" << RESET << std::endl;
	else
		std::cout << RED << "IT IS NOT INSIDE!" << RESET << std::endl;
}

int	main( void ) {
	test1();
	test2();
	test3Float();
	test4Float();
	test5Float();
}

