/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/19 18:48:43 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) {
	validateAndProcessInput(input);
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
	if (arguments.size() != 1)
		throw std::runtime_error("Error: Invalid input!");
	else
		std::cout << GREEN << "Result: " << arguments.top() << RESET << std::endl;
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
	if (token.length() == 1 && std::isdigit(token[0]))
		arguments.push(std::stod(token));
	else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		performOperation(token[0]);
	else
		throw std::runtime_error("Error: Invalid input!");
}

void RPN::performOperation(char op) {
		if (arguments.size() < 2)
			throw std::runtime_error("Error: Invalid input!");
		double operand2 = arguments.top();
		arguments.pop();
		double operand1 = arguments.top();
		arguments.pop();

		switch (op) {
			case '+':
				arguments.push(operand1 + operand2);
				break;
			case '-':
				arguments.push(operand1 - operand2);
				break;
			case '*':
				arguments.push(operand1 * operand2);
				break;
			case '/':
				if (operand2 == 0) {
					throw std::runtime_error("Error: Division by zero!");
				}
				arguments.push(operand1 / operand2);
				break;
			default:
				throw std::runtime_error("Error: Invalid operator!");
		}
}
