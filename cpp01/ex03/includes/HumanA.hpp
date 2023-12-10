/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:52 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/29 14:24:16 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class	HumanA {
	private:
		std::string name;
		Weapon		&weapon;

	public:
		HumanA(std::string Name, Weapon &weapon);
		~HumanA(void);

		void	attack();
};

# endif
