/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:28:44 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/24 18:21:21 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook Constructor Called" << std::endl;
	this->index = -1;
	this->flag	= true;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor Called" << std::endl;
	return;
}



bool	PhoneBook::ValidateInformation(std::string input, int type) {
	if (input.empty())
	{
		std::cout 	<< "Error: It cannot be empty!" << std::endl;
		return (false);
	}
	if (type >= 1 && type <= 3)
	{
		for (int i = 0; input[i]; i++) {
			if (!std::isalpha(input[i]) && input[i] != ' ' && input[i] != '-') {
				std::cout 	<< "Error: Names can only contain letters, spaces and hyphens."
							<< std::endl;
				return (false);
			}
		}
	}
	if (type == 4)
	{
		for (int i = 0; input[i]; i++) {
			if (!std::isdigit(input[i]) && input[i] != ' ' && input[i] != '-') {
				std::cout 	<< "Error: Names can only contain digits, spaces and hyphens."
							<< std::endl;
				return (false);
			}
		}
	}
	return (true);
}

std::string		PhoneBook::GetInput(std::string prompt, int type) {
	std::string input;
	while (1)
	{
		std::cout << "Please enter the " << prompt << std::endl << "> ";
		std::getline(std::cin, input);
		int	start = input.find_first_not_of("\n\t\v\r\f");
		int	end = input.find_last_not_of("\n\t\v\r\f");
		if (std::cin.eof())
		{
			this->flag = false;
			return (NULL);
		}
		if (start != end)
		input = input.substr(start, end - start + 1);
		if (ValidateInformation(input, type))
			break ;
	}
	return (input);
}


bool	PhoneBook::AddContact(void) {
	std::string input;

	if (this->index == 8 || this->index == -1)
		this->index = 0;
	input = GetInput("first name:", 1);
	if (this->flag)
		this->contacts[index].SetName(input);
	input = GetInput("last name:", 2);
	if (this->flag)
		this->contacts[index].SetLastName(input);
	input = GetInput("nickname:", 3);
	if (this->flag)
		this->contacts[index].SetNickname(input);
	input = GetInput("phone number:", 4);
	if (this->flag)
		this->contacts[index].SetPhoneNumber(input);
	input = GetInput("darkest secret:", 5);
	if (this->flag)
		this->contacts[index].SetSecret(input);
	if (!this->flag)
		return (false);
	index++;
	return (true);
}
