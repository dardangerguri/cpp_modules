/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/28 14:02:44 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

# define RED "\033[1;31m"
# define RESET "\033[0m"

class	AAnimal {

	public:

		AAnimal(void);
		AAnimal(AAnimal const & copy);
		virtual ~AAnimal(void);

		AAnimal & operator=(const AAnimal & copy);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

	protected:

		std::string	type;
};

# endif
