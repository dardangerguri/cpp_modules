/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/19 17:48:59 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	// std::cout << "ScalarConverter default constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & copy) {
	// std::cout << "ScalarConverter copy constructor called!" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {
	// std::cout << "ScalarConverter destructor called!" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & copy) {
	// std::cout << "ScalarConverter copy assignment operator called!" << std::endl;
	(void)copy;
	return (*this);
}

const char *ScalarConverter::NotDisplayableException::what() const throw() {
	return ("It can't be converted!");
}

bool	ScalarConverter::isChar(std::string parameter) {
	if (parameter.length() == 1 && !isdigit(parameter[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string parameter) {
	if (parameter.length() == 1 && !isdigit(parameter[0]))
		return (true);
	for (size_t i = 0; i < parameter.length(); i++) {
		if (i == 0 && parameter[i] == '-')
			i++;
		if (!isdigit(parameter[i]))
			return (false);
	}
	if (stoi(parameter) > INT_MAX || stoi(parameter) < INT_MIN)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(std::string parameter) {
	int count = 0;
	int count2 = 0;
	for (size_t i = 0; i < parameter.length(); i++)
	{
		if (i == 0 && parameter[i] == '-')
			i++;
		if (parameter[i] == '.')
			count++;
		else if (parameter[i] == 'f')
			count2++;
		else if (!isdigit(parameter[i]))
			return (false);
	}
	if (count == 1 && count2 == 1 && parameter[parameter.length() - 1] == 'f')
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(std::string parameter) {
	int count = 0;
	for (size_t i = 0; i < parameter.length(); i++)
	{
		if (i == 0 && parameter[i] == '-')
			i++;
		if (parameter[i] == '.')
			count++;
		else if (!isdigit(parameter[i]))
			return (false);
	}
	if (count == 1)
		return (true);
	return (false);
}

bool	ScalarConverter::isPseudo(std::string parameter) {
	if (parameter == "-inff" || parameter == "+inff" || parameter == "nanf" \
		|| parameter == "-inf" || parameter == "+inf" || parameter == "nan")
		return (true);
	return (false);
}

void	ScalarConverter::displayChar(char ch, long double c) {
	std::cout << "char: ";
	if (c > CHAR_MAX || c < CHAR_MIN)
		std::cout << "impossible" << std::endl;
	else if (isprint(ch))
		std::cout << "'" << ch << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::displayInt(int i, long double c) {
	std::cout << "int: ";
	if (c > INT_MAX || c < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void	ScalarConverter::displayFloat(float f, long double c) {
	std::cout << "float: ";
	if (c > FLT_MAX || c < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else {
		if (f - static_cast<int>(f) == 0)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
}

void	ScalarConverter::displayDouble(double d, long double c) {
	std::cout << "double: ";
	if (c > DBL_MAX || c < -DBL_MAX)
		std::cout << "impossible" << std::endl;
	else {
		if (d - static_cast<int>(d) == 0)
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
}

void	ScalarConverter::displayPseudo(std::string parameter) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << parameter << std::endl;
	std::cout << "double: " << parameter << std::endl;
}

void	ScalarConverter::display(long double c, std::string parameter) {
	std::cout << BLUE << "CONVERTING " << parameter << " TO:" << RESET << std::endl;
	displayChar(static_cast<char>(c), c);
	displayInt(static_cast<int>(c), c);
	displayFloat(static_cast<float>(c), c);
	displayDouble(static_cast<double>(c), c);
}

char	ScalarConverter::check_parameter(std::string parameter) {
	if (isChar(parameter))
		return ('c');
	else if (isInt(parameter))
		return ('i');
	else if (isFloat(parameter))
		return ('f');
	else if (isDouble(parameter))
		return ('d');
	else if (isPseudo(parameter))
		return ('p');
	return ('0');
}

void	ScalarConverter::convert(std::string parameter) {
	char c = check_parameter(parameter);
	switch (c)
	{
		case 'c':
			display(parameter[0], parameter);
			break;
		case 'i':
			display(std::stod(parameter), parameter);
			break;
		case 'f':
			display(std::stod(parameter), parameter);
			break;
		case 'd':
			display(std::stod(parameter), parameter);
			break;
		case 'p':
			displayPseudo(parameter);
			break;
		default:
			throw (std::exception());
	}
}