/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/19 17:54:21 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
	// std::cout << "Serializer default constructor called!" << std::endl;
}

Serializer::Serializer(Serializer const & copy) {
	// std::cout << "Serializer copy constructor called!" << std::endl;
	*this = copy;
}

Serializer::~Serializer(void) {
	// std::cout << "Serializer destructor called!" << std::endl;
}

Serializer & Serializer::operator=(const Serializer & copy) {
	// std::cout << "Serializer copy assignment operator called!" << std::endl;
	(void)copy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}


