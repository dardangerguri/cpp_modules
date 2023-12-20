/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:53:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/20 14:30:11 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static	Fixed	getTriangleArea(Point const a, Point const b, Point const c) {
	Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY())
				+ c.getX() * (a.getY() - b.getY())) / 2;
	if (area < 0)
		area = area * -1;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed 	areaTriangle = getTriangleArea(a, b, c);
	Fixed 	areaAPB = getTriangleArea(a, point, b);
	Fixed	areaAPC = getTriangleArea(a, point, c);
	Fixed 	areaBPC = getTriangleArea(b, point, c);

	if (areaTriangle == (areaAPB + areaAPC + areaBPC) && areaAPB != 0 && areaAPC != 0 && areaBPC != 0)
		return (true);
	return (false);
}
