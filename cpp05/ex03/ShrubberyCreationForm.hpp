/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/16 18:03:55 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {

	public:

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & copy);

		std::string const & getTarget(void) const;
		void				toExecute(Bureaucrat const & executor) const;

	private:

		std::string	target;

};

# endif
