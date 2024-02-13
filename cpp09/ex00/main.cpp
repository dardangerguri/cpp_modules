/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/02/13 14:08:28 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw BitcoinExchange::InvalidFile();
		BitcoinExchange btc;
		btc.calculateBitcoinValue(argv[1]);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
