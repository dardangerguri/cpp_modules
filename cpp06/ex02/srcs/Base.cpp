/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/22 13:20:26 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {
	// std::cout << "Base destructor called!" << std::endl;
}

Base * generate(void) {
	int i = std::rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base * p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointing to A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointing to B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointing to C" << std::endl;
	else
		std::cout << "Pointer is NULL" << std::endl;
}

void identify(Base & p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference to A" << std::endl;
	}
	catch (std::exception & e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference to B" << std::endl;
	}
	catch (std::exception & e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference to C" << std::endl;
	}
	catch (std::exception & e) {}
}
