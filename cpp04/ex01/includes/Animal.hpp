/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/28 13:08:17 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RED "\033[1;31m"
# define RESET "\033[0m"

class	Animal {

	public:

		Animal(void);
		Animal(std::string type);
		Animal(Animal const & copy);
		virtual ~Animal(void);

		Animal & operator=(const Animal & copy);

		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:

		std::string	type;
};

# endif
