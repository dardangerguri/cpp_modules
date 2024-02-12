/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/02/12 13:03:15 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc < 2)
			throw std::runtime_error("Error: The format is wrong");
		PmergeMe pmerge(argv);
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
