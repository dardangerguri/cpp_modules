/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/08 18:04:21 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) {
	validateInputandFillContainer(input);
}

RPN::~RPN(void) {
}

void RPN::validateInputandFillContainer(std::string &input) {

	// std::cout << RED << input << RESET << std::endl;
	insertSpace(input);
	for (size_t i = 0; i < input.length(); i++) {
		while (i < input.length() && std::isspace(input[i]))
			i++;
		std::string value = input.substr(i, input.find_first_of(" ", i) - i);
		fillContainer(value);
		i = input.find_first_of(" ", i);
		if (i == std::string::npos)
			break;
		// std::cout << value << std::endl;
	}
	if (arguments.size() < 3 || arguments.size() % 2 == 0)
		throw std::runtime_error("Error: Invalid input!");
}

void RPN::fillContainer(std::string &value) {
	static int element = 0;

	if (element == 0 || element == 1 || element % 2 != 0) {
		std::cout << value << std::endl;
		if (value.length() == 1 && std::isdigit(value[0]))
			arguments.push_back(std::stoi(value));
		else
			throw std::runtime_error("Error: Invalid input!");
	}
	else {
		if (value.length() == 1 && (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/'))
			arguments.push_back(value[0]);
		else
			throw std::runtime_error("Error: Invalid input!");
	}
	element++;
}

void 	RPN::insertSpace(std::string &input) {
	size_t pos = 0;

	while ((pos = input.find_first_of("+-*/", pos)) != std::string::npos) {
		if (pos > 0 && input[pos - 1] != ' ') {
			input.insert(pos, " ");
			pos++;
		}
		// std::cout << input[pos] << std::endl;
		if (pos > 0 && input[pos + 1] != ' ')
			input.insert(pos + 1, " ");
		pos++;
	}
}
