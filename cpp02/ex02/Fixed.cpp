/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:12:15 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/20 10:37:18 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->fixedNbr = 0;
}

Fixed::Fixed(Fixed const & copy) {
	*this = copy;
}

Fixed::Fixed(int const nbr) {
	this->fixedNbr = nbr << this->fractionalBits;
}

Fixed::Fixed(float const nbr) {
	this->fixedNbr = roundf(nbr * (1 << this->fractionalBits));
}

Fixed::~Fixed(void) {
}

Fixed & Fixed::operator=(const Fixed & copy) {
	if (this == &copy)
		return (*this);
	this->fixedNbr = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
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

bool	Fixed::operator>(Fixed const & copy) const {
	return (this->fixedNbr > copy.getRawBits());
}

bool	Fixed::operator<(Fixed const & copy) const {
	return (this->fixedNbr < copy.getRawBits());
}

bool	Fixed::operator>=(Fixed const & copy) const {
	return (this->fixedNbr >= copy.getRawBits());
}

bool	Fixed::operator<=(Fixed const & copy) const {
	return (this->fixedNbr <= copy.getRawBits());
}

bool	Fixed::operator==(Fixed const & copy) const {
	return (this->fixedNbr == copy.getRawBits());
}

bool	Fixed::operator!=(Fixed const & copy) const {
	return (this->fixedNbr != copy.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & copy) const {
	return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & copy) const {
	return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & copy) const {
	return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & copy) const {
	return (Fixed(this->toFloat() / copy.toFloat()));
}

Fixed	&Fixed::operator++(void) {
	this->fixedNbr++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--(void) {
	this->fixedNbr--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

std::ostream &operator << (std::ostream &out, const Fixed &nbr)
{
	out << nbr.toFloat();
	return (out);
}
