/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:12:15 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/20 10:53:08 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->fixedNbr = 0;
}

Fixed::Fixed(Fixed const & copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const nbr) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedNbr = nbr << this->fractionalBits;
}

Fixed::Fixed(float const nbr) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedNbr = roundf(nbr * (1 << this->fractionalBits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed & copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->fixedNbr = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedNbr);
}

void	Fixed::setRawBits(int const raw) {
	this->fixedNbr = raw;
}

int	Fixed::toInt(void) const {
	return (this->fixedNbr >> this->fractionalBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->fixedNbr / (1 << this->fractionalBits));
}

std::ostream &operator << (std::ostream &out, const Fixed &nbr)
{
	out << nbr.toFloat();
	return (out);
}
