/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:04 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/26 16:20:20 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>
#include <algorithm>

void subjectTest() {
	std::cout << YELLOW << "SUBJECT TEST" << RESET << std::endl;
	{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Stack top element " << mstack.top() << std::endl;
	std::cout << "Remove first element!" << std::endl;
	mstack.pop();

	std::cout << "Stack top element " << mstack.top() << std::endl;
	std::cout << "Stack size " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "Stack elements: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	}
	{
	std::cout << std::endl << "--------List Test--------" << std::endl << std::endl;

	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << "List top element " << mstack.back() << std::endl;
	std::cout << "Remove first element!" << std::endl;
	mstack.pop_back();

	std::cout << "List top element " << mstack.back() << std::endl;
	std::cout << "List size " << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "List elements: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::list<int> s(mstack);
	}
}

int main(void) {

	subjectTest();
	std::cout << std::endl;


	return (0);
}
