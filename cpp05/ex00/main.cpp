/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/15 14:43:58 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testDefaultConstructor(void) {
	std::cout << YELLOW << "Test Default Constructor" << RESET << std::endl;
	Bureaucrat bureaucrat;
	std::cout << bureaucrat;
	try {
		bureaucrat.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "Incrementing grade of " << bureaucrat.getName() <<
		" failed: " << e.what() << RESET << std::endl;
	}
	std::cout << bureaucrat;
	try {
		bureaucrat.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "Decrementing grade of " << bureaucrat.getName() <<
		" failed: " << e.what() << RESET << std::endl;
	}
	std::cout << bureaucrat;
	try {
		bureaucrat.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "Decrementing grade of " << bureaucrat.getName() <<
		" failed: " << e.what() << RESET << std::endl;
	}
	std::cout << bureaucrat;
}

void	testNameGradeConstructor(void) {
	std::string const	name = "TEST";
	int					grade = 0;
	std::cout << YELLOW << "Test Name Grade Constructor" << RESET << std::endl;
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		try {
			bureaucrat.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << RED << "Incrementing grade of " << bureaucrat.getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "Creating bureaucrat " << name <<
		" failed: " << e.what() << RESET << std::endl;
	}
	grade = 0;
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		try {
			bureaucrat.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << RED << "Incrementing grade of " << bureaucrat.getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "Creating bureaucrat " << name <<
		" failed: " << e.what() << RESET << std::endl;
	}
	grade = 150;
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		try {
			bureaucrat.decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cerr << RED << "Decrementing grade of " << bureaucrat.getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "Decrementing grade of " << name <<
		" failed: " << e.what() << RESET << std::endl;
	}
}

void	testAssignmentOperator(void) {
	std::cout << YELLOW << "Test Assignment Operator" << RESET << std::endl;
	Bureaucrat bureaucrat("TEST", 150);
	Bureaucrat bureaucrat2("TEST2", 1);
	std::cout << bureaucrat << bureaucrat2 << std::endl;
	bureaucrat = bureaucrat2;
	std::cout << bureaucrat << bureaucrat2 << std::endl;
}

void	testIncrement(void) {
	std::cout << YELLOW << "Test Increment" << RESET << std::endl;
	Bureaucrat bureaucrat("TEST", 50);
	std::cout << bureaucrat;
	try {
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "Incrementing grade of " << bureaucrat.getName() <<
		" failed: " << e.what() << RESET << std::endl;
	}
}

void	testDecrement(void) {
	std::cout << YELLOW << "Test Decrement" << RESET << std::endl;
	Bureaucrat bureaucrat("TEST", 50);
	std::cout << bureaucrat;
	try {
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "Decrementing grade of " << bureaucrat.getName() <<
		" failed: " << e.what() << RESET << std::endl;
	}
}

int		main(void) {
	testDefaultConstructor();
	std::cout << std::endl;
	testNameGradeConstructor();
	std::cout << std::endl;
	testAssignmentOperator();
	std::cout << std::endl;
	testIncrement();
	std::cout << std::endl;
	testDecrement();
	return (0);
}