/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/18 15:54:30 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor called!" << std::endl;
}

Intern::Intern(Intern const & copy) {
	std::cout << "Intern copy constructor called!" << std::endl;
	*this = copy;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called!" << std::endl;
}

Intern & Intern::operator=(const Intern & copy) {
	std::cout << "Intern copy assignment operator called!" << std::endl;
	if (this != &copy) {
	}
	return (*this);
}

const char * Intern::UnknownFormException::what() const throw() {
	return ("Couldn't find form!");
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &target)
{
	int	index = 3;
	std::string	levels[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	for(int	i = 0; i < 3; i++)
		if (levels[i] == formName)
			index = i;
	switch (index)
	{
		case 0:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(target));
		case 1:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 2:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(target));
		case 3:
			throw UnknownFormException();
	}
	// throw UnknownFormException();
	return (NULL);
}