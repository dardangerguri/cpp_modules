/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:46 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/05 15:20:12 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter {

	public:

		Character(void);
		Character(std::string const & name);
		Character(Character const & copy);
		~Character(void);

		Character & operator=(const Character & copy);

		void setName(std::string const & name);
		std::string const & getName(void) const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void displayCharacterInventory(void);

	private:

		std::string		name;
		AMateria*		inventory[4];
};

# endif
