/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/02/06 16:28:46 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	{
		std::cout << YELLOW << "\tSubject tests" << RESET << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << RED << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	{
		std::cout << YELLOW << "\tMy test" << RESET << std::endl;

		try {
			Span sp = Span(10);
			sp.addManyNumbers(10);
			sp.displayVector();
			std::cout << RED << sp.shortestSpan() << RESET << std::endl;
			std::cout << GREEN << sp.longestSpan() << RESET << std::endl;
		}
		catch (std::exception & e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
}
