/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/22 13:45:33 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

template <typename T> void	swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T	min(T a, T b)
{
	return ((a < b) ? a : b);

}

template <typename T> T	max(T a, T b)
{
	return ((a > b) ? a : b);
}

# endif