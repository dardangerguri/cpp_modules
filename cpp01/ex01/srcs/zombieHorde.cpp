/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:31:46 by dardangergu       #+#    #+#             */
/*   Updated: 2023/12/10 22:38:12 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];
	int i;
	for (i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}