/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:51:59 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/23 17:23:34 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Gets the input, modifies it by removing the whitespace in the beginning
	and the end, and also changes it to uppercase letters.

	Return: The modified string!
 */
std::string		get_input(PhoneBook *phonebook) {
	std::string input;
	(void)phonebook;

	std::cout << "Enter a command: ";
	std::cin >> input;


	return (input);
}

int	main(void) {
	PhoneBook	phonebook;

	std::cout	<< "---------------------------------------------" << std::endl
				<< "|         Welcome to this PhoneBook         |" << std::endl
				<< "---------------------------------------------" << std::endl;
	while (1) {
		std::string input = get_input(&phonebook);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			std::cout << "ADD" << std::endl;
		else if (input == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
