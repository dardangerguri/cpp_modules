/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/13 13:19:35 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
	validateInput(argv);
	sortAndDisplay();
}

PmergeMe::~PmergeMe(void) {
}

void	PmergeMe::validateInput(char **argv) {
	int i = 1;
	int number;
	while (argv[i] != NULL)
	{
		number = convertStringToInt(argv[i]);
		checkForDuplicates(number);
		vector.push_back(number);
		deque.push_back(number);
		i++;
	}
}

int	PmergeMe::convertStringToInt(std::string str) {
	std::stringstream s;
	s << str;
	int n;
	while (!(s >> n) || s.fail() || !s.eof() || n <= 0)
	{
		throw std::runtime_error("Error: Invalid input!");
	}
	return (n);
}

void	PmergeMe::checkForDuplicates(int number) {
	for (const auto& element : vector) {
		if (number == element) {
			throw std::runtime_error("Error: Duplicate input!");
		}
	}
}

void PmergeMe::sortAndDisplay() {
    std::cout << GREEN << "Sorting with std::vector\n" << RESET
              << "Before: ";
    displayContent(vector);
	std::chrono::high_resolution_clock::time_point vecStart, vecEnd;
	vecStart = std::chrono::high_resolution_clock::now();
    sortVector(vector);
	vecEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vecElapsedTime = vecEnd - vecStart;
    std::cout << "After: ";
    displayContent(vector);

    std::cout << GREEN << "Sorting with std::deque\n" << RESET
              << "Before: ";
    displayContent(deque);
	std::chrono::high_resolution_clock::time_point deqStart, deqEnd;
	deqStart = std::chrono::high_resolution_clock::now();
    sortDeque(deque);
	deqEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> deqElapsedTime = deqEnd - deqStart;
    std::cout << "After: ";
    displayContent(deque);

	std::cout << YELLOW << "Time to process a range of " << vector.size()
	<< " elements with std::vector : " << vecElapsedTime.count() << " us" << RESET << std::endl;

	std::cout << YELLOW << "Time to process a range of " << deque.size()
	<< " elements with std::deque : " << deqElapsedTime.count() << " us" << RESET << std::endl;
}

void PmergeMe::displayContent(const std::vector<int>& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayContent(const std::deque<int>& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void	PmergeMe::sortVector(std::vector<int> &vector) {
	if (vector.size() == 1)
		return ;
	int	middle = vector.size() / 2;
	std::vector<int> left = std::vector<int>(vector.begin(), vector.begin() + middle);
	std::vector<int> right = std::vector<int>(vector.begin() + middle, vector.end());
	sortVector(left);
	sortVector(right);
	mergeVectors(vector, left, right);
}

void	PmergeMe::sortDeque(std::deque<int> &deque) {
	if (deque.size() == 1)
		return ;
	int	middle = deque.size() / 2;
	std::deque<int> left = std::deque<int>(deque.begin(), deque.begin() + middle);
	std::deque<int> right = std::deque<int>(deque.begin() + middle, deque.end());
	sortDeque(left);
	sortDeque(right);
	mergeDeques(deque, left, right);
}

void	PmergeMe::mergeVectors(std::vector<int> &vector, std::vector<int> &left, std::vector<int> &right) {
	size_t l = 0;
	size_t r = 0;
	size_t v = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] < right[r]) {
			vector[v] = left[l];
			l++;
		}
		else {
			vector[v] = right[r];
			r++;
		}
		v++;
	}
	while (l < left.size()) {
		vector[v] = left[l];
		l++;
		v++;
	}
	while (r < right.size()) {
		vector[v] = right[r];
		r++;
		v++;
	}
}

void	PmergeMe::mergeDeques(std::deque<int> &deque, std::deque<int> &left, std::deque<int> &right) {
	size_t l = 0;
	size_t r = 0;
	size_t v = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] < right[r]) {
			deque[v] = left[l];
			l++;
		}
		else {
			deque[v] = right[r];
			r++;
		}
		v++;
	}
	while (l < left.size()) {
		deque[v] = left[l];
		l++;
		v++;
	}
	while (r < right.size()) {
		deque[v] = right[r];
		r++;
		v++;
	}
}
