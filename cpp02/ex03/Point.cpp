/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:12:15 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/20 11:07:43 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) {
	this->x = 0;
	this->y = 0;
}

Point::Point(Fixed const x, Fixed const y) {
	this->x = x;
	this->y = y;
}

Point::Point(Point const & copy) {
	this->x = copy.getX();
	this->y = copy.getY();
}

Point::~Point(void) {
}

Point & Point::operator=(const Point & copy) {
	if (this == &copy)
		return (*this);
	return (*this);
}

Fixed const Point::getX(void) const {
	return (this->x);
}

Fixed const Point::getY(void) const {
	return (this->y);
}

