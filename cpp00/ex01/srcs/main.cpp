/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:51:59 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/10 21:46:35 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
	Gets the command input, removes the whitespace from the beginning and end,
	and also changes it to uppercase letters.
	Return: The modified string!
 */
static std::string		GetInput(void) {
	std::string input;
	std::cout << YELLOW << "What can I help you with?" << std::endl << "> " << RESET;
	std::getline(std::cin, input);
	int	start = input.find_first_not_of(" \n\t\v\r\f");
	int	end = input.find_last_not_of(" \n\t\v\r\f");
	if (std::cin.eof())
		return ("EXIT");
	if (start == end && start < 0)
		return (input);
	for (int i = 0; input[i]; i++)
		input[i] = std::toupper(input[i]);
	return (input.substr(start, end - start + 1));
}

/*
	If the command is invalid, it writes an error message,
	and provides instructions
*/
static void	invalid_command(void) {
	std::cout	<< RED
				<< "Uh-oh! You seem to be lost in the dgerguri's PhoneBook!"
				<< RESET << std::endl
				<< "Please navigate by entering one of these options:" << std::endl
				<< "	ADD: add a contact," << std::endl
				<< "	SEARCH: search for a contact," << std::endl
				<< "	EXIT: exit the dgerguri's PhoneBook." << std::endl;
}

int	main(void) {
	PhoneBook	phonebook;

	std::cout	<< YELLOW
				<< "---------------------------------------------" << std::endl
				<< "|     Welcome to dgerguri's PhoneBook!      |" << std::endl
				<< "---------------------------------------------" << std::endl
				<< RESET << std::endl;
	while (1) {
		std::string input = GetInput();
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			if (!phonebook.AddContact())
				break ;
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.SearchContact())
				break ;
		}
		else
			invalid_command();
	}
	std::cout << "Bye! Thank you for using the PhoneBook!" << std::endl;
	return (0);
}
