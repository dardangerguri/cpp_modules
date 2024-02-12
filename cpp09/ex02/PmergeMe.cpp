/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/12 18:07:50 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
	validateInput(argv);
	displayContentVector(); //delete
	sortAlgorithm();
}

PmergeMe::~PmergeMe(void) {
}

void PmergeMe::displayContentVector()
{
    for (const auto& element : vector) {
        std::cout << element << " ";
    }
	std::cout << std::endl;
}

void PmergeMe::displayContentDeque()
{
    for (const auto& element : deque) {
        std::cout << element << " ";
    }
	std::cout << std::endl;
}


//SORT

void	PmergeMe::sortAlgorithm() {
	std::cout << GREEN "Sorting with std::vector\n" RESET
	<< "Before: ";
	displayContentVector();
	sortVector(vector);
	std::cout << "After: ";
	displayContentVector();



	// std::cout << std::endl << GREEN "Sorting with std::deque\n" RESET
	// << "Before: ";
	// displayContentDeque();
	// // sortDeque();
	// std::cout << "After: ";
	// displayContentVector();

	// std::cout << std::endl << "Time to process a range of " << vector.size() << " elements with std::vector : " << std::endl;
	// std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << std::endl;
}


void	PmergeMe::sortVector(std::vector<int> &vector) {


	if (vector.size() == 1)
		return ;
	int	middle = vector.size() / 2;

	std::vector<int> left = std::vector<int>(vector.begin(), vector.begin() + middle);
	std::vector<int> right = std::vector<int>(vector.begin() + middle, vector.end());
	sortVector(left);
	sortVector(right);
	combineVectors(vector, left, right);
	// for (const auto& element : vector) {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
}


void	PmergeMe::combineVectors(std::vector<int> &vector, std::vector<int> &left, std::vector<int> &right) {

	size_t v = 0;
	size_t l = 0;
	size_t r = 0;

	for (const auto& element : left) {
		std::cout << element << " ";
	}
	std::cout << "       ";

	for (const auto& element : right) {
		std::cout << element << " ";
	}
	std::cout << "       ";
	while (l < left.size() && r < right.size()) {
		if (left[l] > right[r]) {
			std::cout << " 1 ";
			vector[v] = right[r];
			v++;
			vector[v] = left[r];
			// vector[v] = left[l];
			// v++;
			// r++;
			l++;
		}
		else {
			std::cout << " 2 ";
			vector[v] = left[r];
			v++;
			// v++;
			// v++;
			// l++;
			r++;
		}
			// r++;
			// l++;
	}

	for (const auto& element : vector) {
		std::cout << RED << element << " ";
	}
	std::cout << "       " RESET;
std::cout << std::endl;
	// if ()


}


// VALIDATE

void	PmergeMe::checkDoubles(int number)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (number == *it)
			throw std::runtime_error("Error: Invalid input!");
	}
}

int	PmergeMe::checkInt(std::string str) {
	std::stringstream s;
	s << str;
	int n;
	while (!(s >> n) || s.fail() || !s.eof() || n <= 0)
	{
		throw std::runtime_error("Error: Invalid input!");
	}
	return (n);
}

void	PmergeMe::validateInput(char **argv) {
	int i = 1;
	int number;
	while (argv[i] != NULL)
	{
		number = checkInt(argv[i]);
		checkDoubles(number);
		vector.push_back(number);
		deque.push_back(number);
		i++;
	}
}
