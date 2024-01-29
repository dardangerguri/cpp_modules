/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/29 14:06:53 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called!" << std::endl;
	std::srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called!" << std::endl;
	std::srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : AForm(copy) {
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & copy) {
	std::cout << "RobotomyRequestForm copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->target = copy.target;
	}
	return (*this);
}

std::string const & RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}

void	RobotomyRequestForm::toExecute(Bureaucrat const & executor) const {
	if (this->getIsSignedBool() == false)
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << "Brrrrrrrrrrrr" << std::endl;
	if (std::rand() % 2) {
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	}
	else
		std::cout << this->target << " has resisted to the robotomy." << std::endl;
}

