/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/17 17:04:13 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern {

	public:

		Intern(void);
		Intern(Intern const & copy);
		~Intern(void);

		Intern & operator=(const Intern & copy);

		AForm *	makeForm(std::string const & formName, std::string const & target);

		class UnknownFormException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:

};

# endif
