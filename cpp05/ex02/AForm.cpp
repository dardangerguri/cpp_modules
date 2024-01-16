/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/16 18:04:34 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("Default"), isSigned(false), gradeToSign(150), gradeToExec(150){
	std::cout << "AForm default constructor called!" << std::endl;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	std::cout << "AForm constructor called!" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec) {
	std::cout << "AForm copy constructor called!" << std::endl;
	*this = copy;
}

AForm::~AForm(void) {
	std::cout << "AForm destructor called!" << std::endl;
}

AForm & AForm::operator=(const AForm & copy) {
	std::cout << "AForm copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->isSigned = copy.isSigned;
	}
	return (*this);
}

std::string const &	AForm::getName(void) const {
	return (this->name);
}

std::string	AForm::getIsSigned(void) const {
	if (this->isSigned == true)
		return ("Form is signed!");
	else
		return ("Form is not signed!");
}

bool	AForm::getIsSignedBool(void) const {
	return (this->isSigned);
}

int	AForm::getGradeToSign(void) const {
	return (this->gradeToSign);
}

int	AForm::getGradeToExec(void) const {
	return (this->gradeToExec);
}

void	AForm::beSigned(Bureaucrat & target) {
	if (target.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else if (this->isSigned == true)
		throw AForm::AFormAlreadySignedException();
	else
		this->isSigned = true;
}

void	AForm::execute(Bureaucrat const & target) const {
	if (this->isSigned == false)
		throw AForm::AFormNotSignedException();
	else if (target.getGrade() > this->gradeToExec)
		throw AForm::GradeTooLowException();
	this->toExecute(target);
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char	*AForm::AFormAlreadySignedException::what() const throw() {
	return ("Form already signed!");
}

const char	*AForm::AFormNotSignedException::what() const throw() {
	return ("Form not signed!");
}

std::ostream	&operator<<(std::ostream &os, AForm &target) {
	os << target.getName() << " " << target.getIsSigned() << std::endl;
	os << "Form grade to sign: " << target.getGradeToSign() << std::endl;
	os << "Form grade to exec: " << target.getGradeToExec() << std::endl;
	return (os);
}
