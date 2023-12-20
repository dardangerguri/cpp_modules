/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:12:15 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/20 15:31:14 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y) {
}

Point::Point(Point const & copy) : x(copy.getX()), y(copy.getY()) {
}

Point::~Point(void) {
}

Point & Point::operator=(const Point & copy) {
	(void)copy;
	return (*this);
}

Fixed const Point::getX(void) const {
	return (this->x);
}

Fixed const Point::getY(void) const {
	return (this->y);
}

