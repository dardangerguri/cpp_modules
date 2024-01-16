/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/15 16:49:25 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Bureaucrat default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
	std::cout << "Bureaucrat constructor called!" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
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
		this->grade = copy.grade;
	}
	return (*this);
}

std::string const & Bureaucrat::getName(void) const {
	return (this->name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void) {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else {
		std::cout << "Bureaucrat " << this->name << " grade " << this->grade << " incremented to " ;
		this->grade--;
		std::cout << this->grade << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void) {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else {
		std::cout << "Bureaucrat " << this->name << " grade " << this->grade << " decremented to " ;
		this->grade++;
		std::cout << this->grade << std::endl;
	}
}

void	Bureaucrat::signForm(Form & target) {
	try
	{
		target.beSigned(*this);
		std::cout << this->name << " signs " << target.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't sign " << target.getName() << " because " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &target) {
	os << target.getName() << RESET << ", bureaucrat grade " << target.getGrade() << "." << std::endl;
	return (os);
}
