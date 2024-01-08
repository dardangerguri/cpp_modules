/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/08 09:55:59 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void) {
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 150);

	bureaucrat->incrementGrade();
	std::cout << bureaucrat->getGrade() << std::endl;
	try
	{
		bureaucrat->decrementGrade();
		std::cout << bureaucrat->getGrade() << std::endl;
		bureaucrat->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Incrementing grade of " << bureaucrat->getName() <<
		" failed: " << e.what() << std::endl;
	}

	delete bureaucrat;
	return (0);
}