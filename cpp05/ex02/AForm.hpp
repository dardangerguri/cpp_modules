/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/16 18:02:40 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "Bureaucrat.hpp"

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class	Bureaucrat;
class	AForm {

	public:

		AForm(void);
		AForm(std::string const name, int gradeToSign, int gradeToExec);
		AForm(AForm const & copy);
		virtual ~AForm(void);

		AForm & operator=(const AForm & copy);

		std::string const & getName(void) const;
		std::string			getIsSigned(void) const;
		bool				getIsSignedBool(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;

		void				beSigned(Bureaucrat & target);
		void				execute(Bureaucrat const & target) const;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	AFormAlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	AFormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:

		std::string const	name;
		bool				isSigned;
		int	const			gradeToSign;
		int	const			gradeToExec;

	protected:

		virtual void		toExecute(Bureaucrat const & executor) const = 0;
};

	std::ostream	&operator<<(std::ostream &os, AForm &target);

# endif
