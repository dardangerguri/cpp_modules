/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/19 09:58:00 by dardangergu      ###   ########.fr       */
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
		for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it) {
			if (number == *it) {
				throw std::runtime_error("Error: Duplicate input!");
		}
	}
}

void PmergeMe::sortAndDisplay() {
    std::cout << GREEN << "Sorting with std::vector\n" << RESET
              << "Before: ";
    displayContent(vector);
	// std::chrono::high_resolution_clock::time_point vecStart, vecEnd;
	// vecStart = std::chrono::high_resolution_clock::now();
    sortVector(vector);
	// vecEnd = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double, std::micro> vecElapsedTime = vecEnd - vecStart;
    // std::cout << "After: ";
    // displayContent(vector);

    // std::cout << GREEN << "Sorting with std::deque\n" << RESET
    //           << "Before: ";
    // displayContent(deque);
	// std::chrono::high_resolution_clock::time_point deqStart, deqEnd;
	// deqStart = std::chrono::high_resolution_clock::now();
    // sortDeque(deque);
	// deqEnd = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double, std::micro> deqElapsedTime = deqEnd - deqStart;
    // std::cout << "After: ";
    // displayContent(deque);

	// std::cout << YELLOW << "Time to process a range of " << vector.size()
	// << " elements with std::vector : " << vecElapsedTime.count() << " us" << RESET << std::endl;

	// std::cout << YELLOW << "Time to process a range of " << deque.size()
	// << " elements with std::deque : " << deqElapsedTime.count() << " us" << RESET << std::endl;
}

void PmergeMe::displayContent(const std::vector<int>& container) {
	for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayContent(const std::deque<int>& container) {
    for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::vector<std::pair<int, int>> PmergeMe::makePairs(std::vector<int> &vector) {

	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < vector.size(); i+=2) {
		std::pair<int, int> pair = std::minmax(vector[i], vector[i + 1]);
		pairs.push_back(pair);
	}
	return (pairs);
}

void PmergeMe::sortPairs(std::vector<std::pair<int, int>> &pairs, int length) {
	if (length == 0)
		return ;
	sortPairs(pairs, length - 1);
	std::pair<int, int> key = pairs[length];
	int i = length - 1;
	while (i >= 0 && pairs[i].second > key.second) {
		pairs[i + 1] = pairs[i];
		i--;
	}
	pairs[i + 1] = key;
}

void PmergeMe::createSortedSequence(std::vector<std::pair<int, int>> &pairs) {
	vector.clear();
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++) {
		vector.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	int s1 = pend.front();
	pend.erase(pend.begin());
	vector.insert(vector.begin(), s1);

}

void	PmergeMe::sortVector(std::vector<int> &vector) {

	//GET THE STRAGGLER!!!
	int straggler = -1;
	if (vector.size() % 2) {
		straggler = vector.back();
		vector.pop_back();
	}
	// std::cout << straggler << "     " << vector.back() << std::endl;
	std::cout << YELLOW << "Vec: "; displayContent(vector); std::cout << RESET << std::endl;


	// MAKE THE PAIRS!!!

	std::vector<std::pair<int, int>> pairs = makePairs(vector);
	    for (const auto& pair : pairs) {
        std::cout << RED << "(" << pair.first << ", " << pair.second << ")" RESET << std::endl;
    }

	// RECURSIVELY SORT PAIRS BASED ON TE GREATER PART!!!!
		sortPairs(pairs, (pairs.size() - 1));
	 	for (const auto& pair : pairs) {
        std::cout << BLUE << "(" << pair.first << ", " << pair.second << ")" RESET << std::endl;
	}

	// CREATE A SORTED S SEQUENCE!!!
	createSortedSequence(pairs);

	(void)straggler;
}

void	PmergeMe::sortDeque(std::deque<int> &deque) {
	if (deque.size() == 1)
		return ;
	int	middle = deque.size() / 2;
	std::deque<int> left = std::deque<int>(deque.begin(), deque.begin() + middle);
	std::deque<int> right = std::deque<int>(deque.begin() + middle, deque.end());
	sortDeque(left);
	sortDeque(right);
	// mergeDeques(deque, left, right);
}
