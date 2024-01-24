/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/24 15:03:14 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

template <class T> class Array {
	private:

		unsigned int	size;
		T				*array;

	public:

		Array(void);
		Array(unsigned int n);
		Array(Array const &copy);
		Array &operator=(Array const &src);
		~Array(void);

		T &operator[](unsigned int index) const;
		unsigned int	getSize(void) const;

		class OutOfBoundsException : public std::exception {
			public:
				const char *what() const throw()
				{
					return ("Index out of bounds!");
				}
		};
};

# include "Array.tpp"
# endif
