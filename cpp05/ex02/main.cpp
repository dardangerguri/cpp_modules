/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:24 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/08 10:30:46 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void) {
	Bureaucrat *bureaucrat = new Bureaucrat("TestBureaucrat", 15);
	Form	*form = new Form("TestForm", 20, 100);

	try
	{
		form->beSigned(*bureaucrat);
		bureaucrat->signForm(*form);
		std::cout << bureaucrat;
		std::cout << form;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete bureaucrat;
	return (0);
}