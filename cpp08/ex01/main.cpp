/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/25 17:06:25 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	std::cout << YELLOW << "\tSubject tests" << RESET << std::endl;

	Span sp = Span(5);

  	sp.addNumber(6);
  	sp.addNumber(3);
  	sp.addNumber(17);
  	sp.addNumber(9);
  	sp.addNumber(11);

  	std::cout << sp.shortestSpan() << std::endl;
  	std::cout << sp.longestSpan() << std::endl;

	std::cout << YELLOW << "\tMy tests" << RESET << std::endl;

}