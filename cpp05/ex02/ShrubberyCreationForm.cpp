/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:15 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/16 18:11:51 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm(copy) {
	std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & copy) {
	std::cout << "ShrubberyCreationForm copy assignment operator called!" << std::endl;
	if (this != &copy) {
		this->target = copy.target;
	}
	return (*this);
}

std::string const & ShrubberyCreationForm::getTarget(void) const {
	return (this->target);
}

void	ShrubberyCreationForm::toExecute(Bureaucrat const & executor) const {
	if (this->getIsSignedBool() == false)
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
    std::string outfile = this->getTarget();
    outfile.append("_shrubbery");
	std::ofstream out_file(outfile.c_str());
	out_file << "       _-_" << std::endl
		 << "   /~~    ~~\\" << std::endl
		 << " /~~         ~~\\" << std::endl
		 << "{               }" << std::endl
		 << " \\  _-     -_  /" << std::endl
		 << "   ~  \\\\ //  ~" << std::endl
		 << "_- -   | | _- _" << std::endl
		 << "       | |" << std::endl
		 << "       | |" << std::endl
		 << "      /| |\\ " << std::endl
		 << "____/  | |  \\____" << std::endl;
	out_file.close();
}