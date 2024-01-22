/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/22 13:25:07 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	Base *	p;

	for (int i = 0; i < 10; i++)
	{
		std::cout << GREEN "Test " << i + 1 << " - " RESET;
		p = generate();
		std::cout << "\tPointer: " << RED;
		identify(p);
		std::cout << RESET "\t\tReference: " << BLUE;
		identify(*p);
		std::cout << RESET;
		delete (p);
		if (i < 9)
		std::cout << std::endl;
	}
	return (0);
}
