/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:32:49 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/19 17:19:02 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <float.h>
#include <limits>

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

		void convert(std::string parameter);

		class NotDisplayableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:

		char check_parameter(std::string parameter);
		void display(long double c, std::string parameter);

		bool isChar(std::string parameter);
		bool isInt(std::string parameter);
		bool isFloat(std::string parameter);
		bool isDouble(std::string parameter);
		bool isPseudo(std::string parameter);

		void displayChar(char ch, long double c);
		void displayInt(int i, long double c);
		void displayFloat(float f, long double c);
		void displayDouble(double d, long double c);
		void displayPseudo(std::string parameter);

};

# endif
