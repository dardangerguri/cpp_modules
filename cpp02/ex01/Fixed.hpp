/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:55 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/11 17:03:50 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class	Fixed {

	public:
		Fixed(void);
		Fixed(Fixed const & copy);
		Fixed(int const nbr);
		Fixed(float const nbr);
		~Fixed(void);

		Fixed & operator=(const Fixed & copy);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int 				fixedNbr;
		static const int	fractionalBits = 8;

};

std::ostream &operator << (std::ostream &out, const Fixed &nbr);

# endif
