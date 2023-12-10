/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:53 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/01 14:51:46 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl		harl;
	std::string	level;

	if (argc != 2) {
		std::cout 	<< RED<< "Error! " << RESET
					<< "USAGE: ./harlFilter <level>" << std::endl;
		return (1);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}
