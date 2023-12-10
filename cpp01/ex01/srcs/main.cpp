/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2023/12/10 22:38:48 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int main(void) {
	int size;
	int i;

	size = 5;
	Zombie *horde = zombieHorde(size, "DARDAN");
	for (i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}