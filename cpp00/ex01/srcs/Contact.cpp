/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:20:17 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/25 19:18:02 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
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

std::string	Contact::GetFirstName(void) {
	return (this->first_name);
}

std::string	Contact::GetLastName(void) {
	return (this->last_name);
}

std::string	Contact::GetNickname(void) {
	return (this->nickname);
}

std::string	Contact::GetPhoneNumber(void) {
	return (this->phone_number);
}

std::string	Contact::GetSecret(void) {
	return (this->secret);
}
