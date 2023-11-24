/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:20:17 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/24 18:14:03 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact Constructor Called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact Destructor Called" << std::endl;
	return;
}

void	Contact::SetName(std::string first_name) {
	first_name[0] = std::toupper(first_name[0]);
	for (int i = 1; first_name[i]; i++)
		first_name[i] = std::tolower(first_name[i]);
	this->first_name = first_name;
}

void	Contact::SetLastName(std::string last_name) {
	last_name[0] = std::toupper(last_name[0]);
	for (int i = 1; last_name[i]; i++)
		last_name[i] = std::tolower(last_name[i]);
	this->last_name = last_name;
}

void	Contact::SetNickname(std::string nickname) {
	nickname[0] = std::toupper(nickname[0]);
	for (int i = 1; nickname[i]; i++)
		nickname[i] = std::tolower(nickname[i]);
	this->nickname = nickname;
}

void	Contact::SetPhoneNumber(std::string phone_number) {
	this->phone_number = phone_number;
}

void	Contact::SetSecret(std::string secret) {
	this->secret = secret;
}
