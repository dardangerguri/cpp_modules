/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/10 16:03:25 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		try {
			Converter::
		}
		catch () {
			std::cout << RED << "Input cannot be converted!" << RESET << std::endl;
		}

		return (0);
	}
	std::cout << "Usage: ./converter <toConvert>" << std::endl;
	return (1);
}
