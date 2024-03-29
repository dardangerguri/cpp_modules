/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:46 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/05 14:49:23 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {

	public:

		MateriaSource(void);
		MateriaSource(MateriaSource const & copy);
		~MateriaSource(void);

		MateriaSource & operator=(const MateriaSource & copy);

		void		learnMateria(AMateria * m);
		AMateria*	createMateria(std::string const & type);

		void		displayInventory(void);

	private:

		AMateria*		inventory[4];
};

# endif
