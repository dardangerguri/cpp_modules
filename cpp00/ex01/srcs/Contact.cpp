/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contac.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:20:17 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/23 17:26:27 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact Constructor Called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact Destructor Called" << std::endl;
	return;
}
