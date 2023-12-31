/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:28:44 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/13 14:23:06 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->index = -1;
	this->flag	= true;
}

PhoneBook::~PhoneBook(void) {
}

bool	PhoneBook::ValidateInformation(std::string input, int type) {
	if (input.empty() || std::isspace(input[0]))
	{
		std::cout 	<< RED << "Error: It cannot be empty!"
					<< RESET << std::endl;
		return (false);
	}
	else if (type >= 1 && type <= 3)
	{
		for (int i = 0; input[i]; i++) {
			if (!std::isalpha(input[i]) && input[i] != ' ' && input[i] != '-') {
				std::cout 	<< RED << "Error: "
							<< "Names can only contain letters, spaces and '-'."
							<< RESET << std::endl;
				return (false);
			}
		}
	}
	else if (type == 4)
	{
		for (int i = 0; input[i]; i++) {
			if (!std::isdigit(input[i]) && input[i] != ' ' && input[i] != '-') {
				std::cout 	<< RED << "Error: "
							<< "Names can only contain digits, spaces and '-'."
							<< RESET << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

std::string		PhoneBook::GetInput(std::string prompt, int type) {
	std::string input;
	while (1 && this->flag)
	{
		std::cout << "Please enter the " << prompt << std::endl << "> ";
		std::getline(std::cin, input);
		int	start = input.find_first_not_of(" \n\t\v\r\f");
		int	end = input.find_last_not_of(" \n\t\v\r\f");
		if (std::cin.eof())
		{
			this->flag = false;
			break ;
		}
		if (start >= 0)
			input = input.substr(start, end - start + 1);
		if (ValidateInformation(input, type))
			break ;
	}
	return (input);
}

int		PhoneBook::checkInt(std::string str) {
	std::stringstream s;
	s << str;
	int n;
	s >> n;

	if (!s.fail())
		return (n);
	else
		return (-1);
}

void	PhoneBook::Trimmed(std::string str) {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
	std::cout << "|";
}

void	PhoneBook::DisplayContacts(void) {
	std::cout	<< "---------------------------------------------" << std::endl
				<< "|     Index|First Name| Last Name|  Nickname|" << std::endl
				<< "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << "|" << std::setw(10) << i << "|";
		Trimmed(this->contacts[i].GetFirstName());
		Trimmed(this->contacts[i].GetLastName());
		Trimmed(this->contacts[i].GetNickname());
		std::cout << std::endl;
		std::cout	<< "---------------------------------------------"
					<< std::endl;
		if (i == 7 || this->contacts[i + 1].GetFirstName().empty())
			break ;
	}
}

bool	PhoneBook::DisplayContactIndex(void) {
	std::string input;
	int			index = 0;

	input = GetInput("index of the contact you want to see:", 0);
	if (!this->flag)
		return (false);
	index = checkInt(input);
	if (index < 0 || index > 7 || this->contacts[index].GetFirstName().empty() || input.size() > 1) {
		std::cout << RED << "Error: Invalid index." << RESET << std::endl;
		return (true);
	}
	else {
		std::cout	<< "---------------------------------------------" << std::endl
					<< "|      dgerguri's PhoneBook Contact Info    |" << std::endl
					<< "---------------------------------------------" << std::endl
					<< "\tFirst Name: " << this->contacts[index].GetFirstName() << std::endl
					<< "\tLast Name: " << this->contacts[index].GetLastName() << std::endl
					<< "\tNickname: " << this->contacts[index].GetNickname() << std::endl
					<< "\tPhone Number: " << this->contacts[index].GetPhoneNumber() << std::endl
					<< "\tDarkest Secret: " << this->contacts[index].GetSecret() << std::endl
					<< "---------------------------------------------" << std::endl;
	}
	return (true);
}

bool	PhoneBook::SearchContact(void) {
	std::cout	<< GREEN
				<< "---------------------------------------------" << std::endl
				<< "|      dgerguri's PhoneBook Search Menu     |" << std::endl
				<< "---------------------------------------------" << std::endl
				<< RESET << std::endl;
	if (this->index == -1) {
		std::cout	<< "There are no contacts in the PhoneBook." << std::endl;
		return (true);
	}
	DisplayContacts();
	if (!DisplayContactIndex())
		return (false);
	return (true);
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
