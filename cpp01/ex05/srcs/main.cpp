/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:53 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/01 14:48:01 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl		harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("WRONG");
	return (0);
}
// int	main(void) {
// 	Harl		harl;
// 	std::string	level;

// 	std::cout 	<< "DEBUG, INFO, WARNING, ERROR, EXIT" << std::endl;
// 				<< "Please enter the level: > ";
// 	std::getline(std::cin, level);
// 	while (level != "EXIT")
// 	{

// 	}
// }
