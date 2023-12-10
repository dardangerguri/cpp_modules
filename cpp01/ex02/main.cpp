/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/27 16:47:37 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout 	<< RED << "\tThe memory addresses:" << RESET << std::endl;
	std::cout 	<< "The memory address of the string: "
				<< RED << &string << RESET << std::endl;
	std::cout 	<< "The memory address held by stringPTR: "
				<< RED << stringPTR << RESET << std::endl;
	std::cout 	<< "The memory address held by stringREF: "
				<< RED << &stringREF << RESET << std::endl << std::endl;

	std::cout 	<< RED << "\tValues: " << RESET << std::endl;
	std::cout 	<< "The value of the string: "
				<< RED << string << RESET << std::endl;
	std::cout 	<< "The value pointed to by stringPTR: "
				<< RED << *stringPTR << RESET << std::endl;
	std::cout	<< "The value pointed to by stringREF: "
				<< RED << stringREF << RESET << std::endl << std::endl;
}


