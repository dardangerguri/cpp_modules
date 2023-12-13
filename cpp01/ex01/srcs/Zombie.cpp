/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:19 by dardangergu       #+#    #+#             */
/*   Updated: 2023/12/13 14:51:35 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {
	std::cout 	<< BLUE << "Zombie created!" << RESET << std::endl;
}


Zombie::~Zombie(void) {
	std::cout 	<< RED << this->name << ": is dead now!" << RESET << std::endl;
}

void Zombie::announce(void) {
	std::cout 	<< GREEN << this->name << ": BraiiiiiiinnnzzzZ..."
				<< RESET << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
