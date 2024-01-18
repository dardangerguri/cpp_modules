/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/16 18:04:02 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(const PresidentialPardonForm & copy);

		std::string const & getTarget(void) const;
		void				toExecute(Bureaucrat const & executor) const;

	private:

		std::string	target;

};

# endif
