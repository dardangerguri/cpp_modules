/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/08 10:11:22 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class	Form;
class	Bureaucrat {

	public:

		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & copy);
		~Bureaucrat(void);

		Bureaucrat & operator=(const Bureaucrat & copy);

		std::string const	getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form & target);

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:

		std::string const	name;
		int					grade;
};

	std::ostream	&operator<<(std::ostream &os, Bureaucrat *target);

# endif
