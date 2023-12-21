/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:55 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/21 17:23:11 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class	DiamondTrap : public ScavTrap, public FragTrap {

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & copy);
		~DiamondTrap(void);

		DiamondTrap & operator=(const DiamondTrap & copy);

		using	ScavTrap::attack;
		void 	whoAmI(void);

	private:
		std::string	name;
};

# endif
