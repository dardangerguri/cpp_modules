/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:00 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/29 18:07:27 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class	HumanB {
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB(std::string Name);
		~HumanB(void);

		void	attack();
		void	setWeapon(Weapon &weapon);
};

# endif
