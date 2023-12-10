/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:19 by dardangergu       #+#    #+#             */
/*   Updated: 2023/12/10 22:14:37 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
}


Zombie::~Zombie(void) {
	std::cout 	<< RED << this->name << ": is dead now!" << RESET << std::endl;
}

void Zombie::announce(void) {
	std::cout 	<< GREEN << this->name << ": BraiiiiiiinnnzzzZ..."
				<< RESET << std::endl;
}
