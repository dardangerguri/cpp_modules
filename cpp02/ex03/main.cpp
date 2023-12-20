/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/20 14:35:56 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main( void ) {
	Point const a(0, -2);
	Point const b(2, 2);
	Point const c(-2, 2);
	Point const p(-0.830f, -0.152f);
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "IT IS INSIDE!" << RESET << std::endl;
	else
		std::cout << RED << "IT IS NOT INSIDE!" << RESET << std::endl;
}

