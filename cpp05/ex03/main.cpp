/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/18 17:07:19 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

	Bureaucrat bureaucrat1("Dardan", 10);
	Bureaucrat bureaucrat2("Dgerguri", 130);

	std::cout << std::endl << YELLOW "Three bureaucrats created:" RESET << std::endl
		<< bureaucrat1 << bureaucrat2 << std::endl;

	Intern intern;

	std::cout << std::endl << YELLOW "Forms" RESET << std::endl;
	AForm *shrubbery = intern.makeForm("shrubbery creation", "shrub");
	AForm *robotomy = intern.makeForm("robotomy request", "robot");
	AForm *presidential = intern.makeForm("presidential pardon", "president");

	try {
		AForm *unknown = intern.makeForm("unknown form", "unknown");
		bureaucrat1.signForm(*unknown);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}


	std::cout << std::endl << YELLOW "Forms signed and execute for first bureaucrat" RESET << std::endl;
	bureaucrat1.signForm(*shrubbery);
	bureaucrat1.signForm(*robotomy);
	bureaucrat1.signForm(*presidential);
	bureaucrat1.executeForm(*shrubbery);
	bureaucrat1.executeForm(*robotomy);
	bureaucrat1.executeForm(*presidential);

	std::cout << std::endl << YELLOW "Forms signed and execute for second bureaucrat" RESET << std::endl;
	bureaucrat2.signForm(*shrubbery);
	bureaucrat2.signForm(*robotomy);
	bureaucrat2.signForm(*presidential);
	bureaucrat2.executeForm(*shrubbery);
	bureaucrat2.executeForm(*robotomy);
	bureaucrat2.executeForm(*presidential);

	std::cout << std::endl;

	delete shrubbery;
	delete robotomy;
	delete presidential;

	return 0;
}