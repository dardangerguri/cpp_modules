/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:40 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/29 14:16:27 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "Weapon.hpp"
# include <iostream>

class	Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string	&getType(void) const;
		void				setType(std::string type);
};

# endif
