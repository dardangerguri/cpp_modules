/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/13 13:15:53 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) {
	validateAndProcessInput(input);
	performOperations();
}

RPN::~RPN(void) {
}

void RPN::validateAndProcessInput(std::string &input) {
	insertSpacesAroundOperators(input);
	size_t pos = 0;
	while (pos < input.length()) {
		pos = input.find_first_not_of(" ", pos);
		if (pos == std::string::npos)
			break;
		size_t endPos = input.find_first_of(" ", pos);
		if (pos == std::string::npos)
			endPos = input.length();
		std::string token = input.substr(pos, endPos - pos);
		processToken(token);
		pos = endPos;
	}
	if (arguments.size() < 3 || arguments.size() % 2 == 0)
		throw std::runtime_error("Error: Invalid input!");
}

void 	RPN::insertSpacesAroundOperators(std::string &input) {
	size_t pos = 0;
	while ((pos = input.find_first_of("+-*/", pos)) != std::string::npos) {
		if (pos > 0 && input[pos - 1] != ' ') {
			input.insert(pos, " ");
			pos++;
		}
		if (pos > 0 && input[pos + 1] != ' ')
			input.insert(pos + 1, " ");
		pos++;
	}
}

void RPN::processToken(std::string &token) {
	static int tokenIndex = 0;

	if (tokenIndex == 0 || tokenIndex == 1 || tokenIndex % 2 != 0) {
		if (token.length() == 1 && std::isdigit(token[0]))
			arguments.push_back(std::stod(token));
		else
			throw std::runtime_error("Error: Invalid input!");
	}
	else {
		if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
			arguments.push_back(token[0]);
		else
			throw std::runtime_error("Error: Invalid input!");
	}
	tokenIndex++;
}

void RPN::performOperations(void) {
	while (arguments.size() >= 3) {
		double operand1 = *arguments.begin();
		arguments.pop_front();
		double operand2 = *arguments.begin();
		arguments.pop_front();
		char op = static_cast<char>(*arguments.begin());
		arguments.pop_front();

		switch (op) {
			case '+':
				arguments.push_front(operand1 + operand2);
				break;
			case '-':
				arguments.push_front(operand1 - operand2);
				break;
			case '*':
				arguments.push_front(operand1 * operand2);
				break;
			case '/':
				if (operand2 == 0) {
					throw std::runtime_error("Error: Division by zero!");
				}
				arguments.push_front(operand1 / operand2);
				break;
			default:
				throw std::runtime_error("Error: Invalid operator!");
		}
	}
	std::cout << GREEN << "Result: " << *arguments.begin() << RESET << std::endl;
}
