/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/01 14:50:45 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void	Harl::debug(void) {
	std::cout << RED << "DEBUG: " << RESET
	<< "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl;
}

void	Harl::info(void) {
	std::cout << RED << "INFO: " << RESET
	<< "I cannot believe adding extra bacon costs more money. You didn’t put"
	" enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void	Harl::warning(void) {
	std::cout << RED << "WARNING: " << RESET
	<< "I think I deserve to have some extra bacon for free. I’ve been coming"
	" for years whereas you started working here since last month."
	<< std::endl;
}

void	Harl::error(void) {
	std::cout << RED << "ERROR: " << RESET
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void	Harl::complain(std::string level) {
	std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = -1;
	while (i < 4) {
		if (lvl[i] == level)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			this->debug();
			i++;
		case 1:
			this->info();
			i++;
		case 2:
			this->warning();
			i++;
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
}
