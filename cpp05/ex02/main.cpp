/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/16 18:10:38 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void) {
	Bureaucrat	bureaucrat1("Dardan", 142);
	Bureaucrat	bureaucrat2("Dgerguri", 65);
	Bureaucrat	bureaucrat3("Dardi", 5);

	std::cout << std::endl << YELLOW "Three bureaucrats created:" RESET << std::endl
		<< bureaucrat1 << bureaucrat2 << bureaucrat3 << std::endl;

	ShrubberyCreationForm	shrubbery("Shrub");
	RobotomyRequestForm		robotomy("Robot");
	PresidentialPardonForm	presidential("President");

	std::cout << std::endl << YELLOW "Three bureaucrats created:" RESET << std::endl
		<< GREEN << shrubbery << RESET
		<< BLUE << robotomy << RESET
		<< RED << presidential << RESET << std::endl;

	std::cout << YELLOW "Shrubbery Creation Form" RESET << std::endl;
	bureaucrat1.signForm(shrubbery);
	bureaucrat1.executeForm(shrubbery);
	bureaucrat3.executeForm(shrubbery);

	std::cout << std::endl << YELLOW "Robotomy Request Form" RESET << std::endl;
	bureaucrat3.signForm(robotomy);
	bureaucrat2.executeForm(robotomy);
	bureaucrat3.executeForm(robotomy);
	bureaucrat2.signForm(robotomy);

	std::cout << std::endl << YELLOW "Presidential Pardon Form" RESET << std::endl;
	bureaucrat1.executeForm(presidential);
	bureaucrat3.signForm(presidential);
	bureaucrat3.executeForm(presidential);

	std::cout << std::endl;
	return (0);
}