/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/10 16:07:56 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	// std::cout << "ScalarConverter default constructor called!" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const & copy) {
	// std::cout << "ScalarConverter copy constructor called!" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {
	// std::cout << "ScalarConverter destructor called!" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & copy) {
	// std::cout << "ScalarConverter copy assignment operator called!" << std::endl;
	if (this != &copy) {
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat *target) {
	os << std::endl;
	return (os);
}
