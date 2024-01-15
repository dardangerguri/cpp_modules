/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/15 16:22:01 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testDefaultConstructor(void) {
	std::cout << YELLOW << "Test Default Constructor" << RESET << std::endl;
	Form form;
	std::cout << "Default form: " << form;
}

void	testFormConstructor(void) {
	std::string	name = "TEST";
	int			gradeToSign = 40;
	int			gradeToExecute = 3;
	std::cout << YELLOW << "Test Form Constructor" << RESET << std::endl;
	std::cout << BLUE << "Grade to sign: " << gradeToSign
				<< ", grade to execute: " << gradeToExecute << RESET << std::endl;
	try {
		Form form(name, gradeToSign, gradeToExecute);
		std::cout << form << GREEN "CREATED!" << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form " << name << " creation failed: " << e.what() << RESET << std::endl;
	}
	gradeToSign = 0;
	gradeToExecute = 150;
	std::cout << BLUE << "Grade to sign: " << gradeToSign
				<< ", grade to execute: " << gradeToExecute << RESET << std::endl;
	try {
		Form form(name, gradeToSign, gradeToExecute);
		std::cout << form << GREEN "CREATED!" << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form " << name << " creation failed: " << e.what() << RESET << std::endl;
	}
	gradeToSign = 1;
	gradeToExecute = 151;
	std::cout << BLUE << "Grade to sign: " << gradeToSign
				<< ", grade to execute: " << gradeToExecute << RESET << std::endl;
	try {
		Form form(name, gradeToSign, gradeToExecute);
		std::cout << form << GREEN "CREATED!" << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form " << name << " creation failed: " << e.what() << RESET << std::endl;
	}
	gradeToSign = 30;
	gradeToExecute = 120;
	std::cout << BLUE << "Grade to sign: " << gradeToSign
				<< ", grade to execute: " << gradeToExecute << RESET << std::endl;
	try {
		Form form(name, gradeToSign, gradeToExecute);
		std::cout << form << GREEN "CREATED!" << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form " << name << " creation failed: " << e.what() << RESET << std::endl;
	}
}

void	testCopyConstructor(void) {
	std::cout << YELLOW << "Test Copy Constructor" << RESET << std::endl;
	Form form("TEST", 150, 2);
	std::cout << form;
	Form form2(form);
	std::cout << form2;
}

void	testAssignmentOperator(void) {
	std::cout << YELLOW << "Test Assignment Operator" << RESET << std::endl;
	Bureaucrat bureaucrat("TEST", 50);
	Form form("TEST", 150, 2);
	bureaucrat.signForm(form);
	Form form2("TEST2", 1, 3);
	std::cout << form << form2;
	form2 = form;
	std::cout << form << form2 << std::endl;
}

void	testSigning(void) {
	std::cout << YELLOW << "Test Signing" << RESET << std::endl;
	Bureaucrat bureaucrat("TEST", 50);
	Form form("TEST", 150, 2);
	std::cout << RED << form << RESET;
	try {
		bureaucrat.signForm(form);
		std::cout << GREEN << form << RESET;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form " << form.getName() << " signing failed: " << e.what() << RESET << std::endl;
	}
	try {
		bureaucrat.signForm(form);
		std::cout << GREEN << form << RESET;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form " << form.getName() << " signing failed: " << e.what() << RESET << std::endl;
	}
	try {
		Form form2("TEST", 0, 2);
		bureaucrat.signForm(form2);
		std::cout << GREEN << form2 << RESET;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form signing failed: " << e.what() << RESET << std::endl;
	}
	Form form3("TEST", 49, 60);
	std::cout << RED << form3 << RESET;
	try {
		bureaucrat.signForm(form3);
		std::cout << GREEN << form3 << RESET;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Form " << form3.getName() << " signing failed: " << e.what() << RESET << std::endl;
	}
}

int		main(void) {
	testDefaultConstructor();
	std::cout << std::endl;
	testFormConstructor();
	std::cout << std::endl;
	testCopyConstructor();
	std::cout << std::endl;
	testAssignmentOperator();
	std::cout << std::endl;
	testSigning();
	return (0);
}