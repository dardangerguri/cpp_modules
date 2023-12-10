/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:19 by dardangergu       #+#    #+#             */
/*   Updated: 2023/12/10 22:38:50 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {
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
