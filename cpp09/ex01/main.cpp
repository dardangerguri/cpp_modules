/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/02/08 15:08:11 by dgerguri         ###   ########.fr       */
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
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
