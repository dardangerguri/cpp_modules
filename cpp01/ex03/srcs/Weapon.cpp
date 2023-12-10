/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:27 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/29 14:16:24 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

const std::string	&Weapon::getType(void) const {
	return ((const std::string&) this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
