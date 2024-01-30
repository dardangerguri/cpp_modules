/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/30 16:00:04 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

template< typename T > void iter(T *array, int len, void (*f)(T &)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template< typename T > void print(T &x) {
	std::cout << x << ' ';
}

template< typename T > void decrement(T &x) {
	x = x - 1;
}

template< typename T > void capitalize(T &x) {
	x = std::toupper(x);
}

template< typename T > void capitalizeString(T &x) {
for (std::string::iterator it = x.begin(); it != x.end(); it++)
		*it = std::toupper(*it);
}

# endif
