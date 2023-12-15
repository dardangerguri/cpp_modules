/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:27 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/15 18:23:21 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
}

Weapon::~Weapon(void) {
}

const std::string	&Weapon::getType(void) const {
	return ((const std::string&) this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
