/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/02/09 00:04:02 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw std::runtime_error("Error: Usage: ./RPN <inverted Polish mathematical expression!>");
		RPN rpn(argv[1]);
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
