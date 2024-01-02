/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/02 16:10:19 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Bureaucrat default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) {
	std::cout << "Bureaucrat copy constructor called!" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called!" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & copy) {
	std::cout << "Bureaucrat copy assignment operator called!" << std::endl;
	if (this != &copy) {
		//do smth here
	}
	return (*this);
}
