/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/08 10:14:55 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class	Bureaucrat;
class	Form {

	public:

		Form(void);
		Form(std::string const name, int gradeToSign, int gradeToExec);
		Form(Form const & copy);
		~Form(void);

		Form & operator=(const Form & copy);

		std::string const	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;

		void				beSigned(Bureaucrat & target);

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	FormAlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:

		std::string const	name;
		bool				isSigned;
		int	const			gradeToSign;
		int	const			gradeToExec;
};

	std::ostream	&operator<<(std::ostream &os, Form *target);

# endif
