/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/19 16:58:39 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		try {
			ScalarConverter scalarConverter;
			scalarConverter.convert(argv[1]);
		}
		catch (std::exception &e) {
			std::cout << RED << "Input cannot be converted!" << RESET << std::endl;
		}

		return (0);
	}
	std::cout << YELLOW "Usage: ./converter <toConvert>"  RESET << std::endl;
	return (1);
}
