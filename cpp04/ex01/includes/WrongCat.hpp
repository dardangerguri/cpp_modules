/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/27 18:28:01 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

	public:

		WrongCat(void);
		WrongCat(WrongCat const & copy);
		~WrongCat(void);

		WrongCat & operator=(const WrongCat & copy);

		void makeSound(void) const;

	private:
};

# endif
