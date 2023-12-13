/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:53 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/13 16:13:13 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl		harl;

	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("WRONG");
	return (0);
}
