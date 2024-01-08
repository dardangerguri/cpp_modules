/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/08 10:29:56 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Default"), isSigned(false), gradeToSign(150), gradeToExec(150){
	std::cout << "Form default constructor called!" << std::endl;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	std::cout << "Form constructor called!" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec) {
	std::cout << "Form copy constructor called!" << std::endl;
	*this = copy;
}

Form::~Form(void) {
	std::cout << "Form destructor called!" << std::endl;
}

Form & Form::operator=(const Form & copy) {
	std::cout << "Form copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->isSigned = copy.isSigned;
	}
	return (*this);
}

std::string const	Form::getName(void) const {
	return (this->name);
}

bool				Form::getIsSigned(void) const {
	return (this->isSigned);
}

int					Form::getGradeToSign(void) const {
	return (this->gradeToSign);
}

int					Form::getGradeToExec(void) const {
	return (this->gradeToExec);
}

void				Form::beSigned(Bureaucrat & target) {
	if (target.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else if (this->isSigned == true)
		throw Form::FormAlreadySignedException();
	else
		this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char *Form::FormAlreadySignedException::what() const throw() {
	return ("Form already signed!");
}

std::ostream	&operator<<(std::ostream &os, Form *target) {
	os << target->getName() << std::endl;
	os << "Form is signed: " << target->getIsSigned() << std::endl;
	os << "Form grade to sign: " << target->getGradeToSign() << std::endl;
	os << "Form grade to exec: " << target->getGradeToExec() << std::endl;
	return (os);
}
