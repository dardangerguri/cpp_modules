/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/16 18:01:39 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : AForm(copy) {
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & copy) {
	std::cout << "PresidentialPardonForm copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->target = copy.target;
	}
	return (*this);
}

std::string const & PresidentialPardonForm::getTarget(void) const {
	return (this->target);
}

void	PresidentialPardonForm::toExecute(Bureaucrat const & executor) const {
	if (this->getIsSignedBool() == false)
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
