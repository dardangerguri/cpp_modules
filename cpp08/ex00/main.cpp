/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/25 16:59:51 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"
# include <list>
# include <deque>
# include <vector>

template <typename T> void	check(std::string containerType, T & container, int toFind)
{
	std::cout << std::endl << "- Searching for " RED "[" << toFind << "]" RESET << std::endl;
	int		result = 0;

	std::cout << containerType << " container: ";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == toFind)
			std::cout << YELLOW;
		std::cout << "[" << *it << "] " RESET;
	}
	std::cout << std::endl;
	try
	{
		result = (::easyfind(container, toFind));
		std::cout << GREEN << "Found " << result << " in the container!" RESET << std::endl;
	}
	catch (std::exception & e)
	{
			std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	testVectorContainer(void) {
	std::cout << YELLOW "\tVECTOR CONTAINER" RESET << std::endl;

	std::vector<int>	container;

	::check("Vector", container, 0);

	for (int it = -4; it < 10; it++)
		container.push_back(it * 2);

	::check("Vector", container, 0);
	::check("Vector", container, 10);
	::check("Vector", container, -6);
	::check("Vector", container, 42);
	::check("Vector", container, -1);
	::check("Vector", container, 12);
	::check("Vector", container, 17);
}

void	testListContainer(void) {
	std::cout << YELLOW "\tLIST CONTAINER" RESET << std::endl;

	std::list<int>	container;

	::check("List", container, 0);

	for (int it = -4; it < 10; it++)
		container.push_back(it * 30);

	::check("List", container, 0);
	::check("List", container, 10);
	::check("List", container, 60);
	::check("List", container, 42);
	::check("List", container, -1);
	::check("List", container, 90);
	::check("List", container, 17);
}

void	testDequeContainer(void) {
	std::cout << YELLOW "\tDEQUE CONTAINER" RESET << std::endl;

	std::deque<int>	container;

	::check("Deque", container, 0);

	for (int it = -4; it < 10; it++)
		container.push_back(it * 200);

	::check("Deque", container, 0);
	::check("Deque", container, 200);
	::check("Deque", container, -6);
	::check("Deque", container, 1600);
	::check("Deque", container, -1);
	::check("Deque", container, 800);
	::check("Deque", container, 17);
}

int main(void) {

	testVectorContainer();
	std::cout << std::endl << std::endl;
	testListContainer();
	std::cout << std::endl << std::endl;
	testDequeContainer();
	return (0);
}
