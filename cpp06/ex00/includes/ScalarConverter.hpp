/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:32:49 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/10 16:03:00 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class	ScalarConverter
{
	public:

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & copy);
		~ScalarConverter(void);

		ScalarConverter & operator=(const ScalarConverter & copy);

	private:

};

std::ostream	&operator<<(std::ostream &os, Bureaucrat *target);

# endif
