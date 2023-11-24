/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:51:59 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/23 20:46:15 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
	Gets the command input, and also changes it to uppercase letters.
	Return: The modified string!
 */
std::string		get_input() {
	std::string input;
	std::cout << "Enter a command: ";
	std::cin >> input;
	if (input.empty())
		return ("no input");
	// if (!std::getline(std::cin, input))
		return ("no input");
	if (std::cin.eof())
		return ("EXIT");
	for (int i = 0; input[i]; i++)
		input[i] = std::toupper(input[i]);
	return (input);
}

int	main(void) {
	PhoneBook	phonebook;

	std::cout	<< "---------------------------------------------" << std::endl
				<< "|         Welcome to this PhoneBook         |" << std::endl
				<< "---------------------------------------------" << std::endl;
	while (1) {
		std::string input = get_input();
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			std::cout << "ADD" << std::endl;
		else if (input == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	std::cout << "Bye! Thank you for using the PhoneBook!" << std::endl;
	return (0);
}
