/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:53:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/21 10:42:27 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// static	Fixed	getTriangleArea(Point const a, Point const b, Point const c) {
// 	Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY())
// 				+ c.getX() * (a.getY() - b.getY())) / 2;
// 	if (area < 0)
// 		area = area * -1;
// 	return (area);
// }

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Point v0(c.getX() - a.getX(), c.getY() - a.getY());
	Point v1(b.getX() - a.getX(), b.getY() - a.getY());
	Point v2(point.getX() - a.getX(), point.getY() - a.getY());

	Fixed dot00 = v0.getX() * v0.getX() + v0.getY() * v0.getY();
	Fixed dot01 = v0.getX() * v1.getX() + v0.getY() * v1.getY();
	Fixed dot02 = v0.getX() * v2.getX() + v0.getY() * v2.getY();
	Fixed dot11 = v1.getX() * v1.getX() + v1.getY() * v1.getY();
	Fixed dot12 = v1.getX() * v2.getX() + v1.getY() * v2.getY();

	Fixed invDenom = Fixed(1) / (dot00 * dot11 - dot01 * dot01);
	Fixed u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	Fixed v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	if ((u >= 0) && (v >= 0) && (u + v < 1))
		return (true);
	return (false);
}

	// Fixed 	areaTriangle = getTriangleArea(a, b, c);
	// Fixed 	areaAPB = getTriangleArea(a, point, b);
	// Fixed	areaAPC = getTriangleArea(a, point, c);
	// Fixed 	areaBPC = getTriangleArea(b, point, c);

	// if (areaTriangle == (areaAPB + areaAPC + areaBPC) && areaAPB != 0 && areaAPC != 0 && areaBPC != 0)
	// 	return (true);