/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/19 18:47:15 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
	sortAndDisplay(argv);
}

PmergeMe::~PmergeMe(void) {
}

void PmergeMe::sortAndDisplay(char **argv) {
	// VECTOR
    std::cout << GREEN << "Sorting with std::vector\n" << RESET
              << "Before: ";
	std::chrono::high_resolution_clock::time_point vecStart, vecEnd;
	vecStart = std::chrono::high_resolution_clock::now();
	validateInput(argv, vector);
    displayContent(vector);
    sortVector(vector);
	vecEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vecElapsedTime = vecEnd - vecStart;
    std::cout << "After: ";
    displayContent(vector);
	std::cout << std::endl;

	// DEQUE
    std::cout << GREEN << "Sorting with std::deque\n" << RESET
              << "Before: ";
	std::chrono::high_resolution_clock::time_point deqStart, deqEnd;
	deqStart = std::chrono::high_resolution_clock::now();
	validateInput(argv, deque);
    displayContent(deque);
    sortDeque(deque);
	deqEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> deqElapsedTime = deqEnd - deqStart;
    std::cout << "After: ";
    displayContent(deque);
	std::cout << std::endl;

	// TIME
	std::cout << YELLOW << "Time to process a range of " << vector.size()
	<< " elements with std::vector : " << vecElapsedTime.count() << " us" << RESET << std::endl;

	std::cout << YELLOW << "Time to process a range of " << deque.size()
	<< " elements with std::deque : " << deqElapsedTime.count() << " us" << RESET << std::endl;
}

/******************************************************************************/
/*								Input									  	  */
/******************************************************************************/

void	PmergeMe::validateInput(char **argv, std::vector<int> &vector) {
	int i = 1;
	int number;
	while (argv[i] != NULL)
	{
		number = convertStringToInt(argv[i]);
		checkForDuplicates(vector, number);
		vector.push_back(number);
		i++;
	}
}

void	PmergeMe::validateInput(char **argv, std::deque<int> &deque) {
	int i = 1;
	int number;
	while (argv[i] != NULL)
	{
		number = convertStringToInt(argv[i]);
		checkForDuplicates(deque, number);
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

void	PmergeMe::checkForDuplicates(std::vector<int> &vector, int number) {
		for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it) {
			if (number == *it) {
				throw std::runtime_error("Error: Duplicate input!");
		}
	}
}

void	PmergeMe::checkForDuplicates(std::deque<int> &deque, int number) {
		for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); ++it) {
			if (number == *it) {
				throw std::runtime_error("Error: Duplicate input!");
		}
	}
}

/******************************************************************************/
/*								Vector Container							  */
/******************************************************************************/

void	PmergeMe::sortVector(std::vector<int> &vector) {
	if (vector.size() == 1)
		return ;

	// 1st step: if the size of the vector is odd, we need to keep the last element!
	int straggler = -1;
	if (vector.size() % 2) {
		straggler = vector.back();
		vector.pop_back();
	}

	// 2nd step: make pairs of thevector elements!
	std::vector<std::pair<int, int>> pairs = makePairs(vector);

	// 3rd step: sort the pairs based on the second element of the pair, in ascending order!
	sortPairs(pairs, (pairs.size() - 1));

	// 4th step: create a sorted sequence from the pairs!
	createSortedSequence(pairs, straggler);
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

	// 3rd step: recursively sort the pairs based on the second element of the pair, in ascending order!
	sortPairs(pairs, length - 1);

	std::pair<int, int> pair = pairs[length];
	int i = length - 1;
	while (i >= 0 && pairs[i].second > pair.second) {
		pairs[i + 1] = pairs[i];
		i--;
	}
	pairs[i + 1] = pair;
}

void PmergeMe::createSortedSequence(std::vector<std::pair<int, int>> &pairs, int straggler) {
	vector.clear();
	std::vector<int> pend;

	// 3th step: insert the second element of the pairs into the vector!
	for (size_t i = 0; i < pairs.size(); i++) {
		vector.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	// 4th step: insert at the beginning of the sorted sequence the first element that was paired with the smallest element of the sorted sequence!
	int s1 = pend.front();
	pend.erase(pend.begin());
	vector.insert(vector.begin(), s1);

	// 5th step: if there is a straggler, we need to insert it into the pend sequence!
	if (straggler != -1) {
		pend.push_back(straggler);
	}

	// 6th step: insert the elements of the pend sequence into the sorted sequence with binary search!
	for (int element : pend) {
		size_t position = std::upper_bound(vector.begin(), vector.end(), element) - vector.begin();
		vector.insert(vector.begin() + position, element);
	}
}

/******************************************************************************/
/*								Deque Container								  */
/******************************************************************************/

void	PmergeMe::sortDeque(std::deque<int> &deque) {
	if (deque.size() == 1)
		return ;

	// 1st step: if the size of the deque is odd, we need to keep the last element!
	int straggler = -1;
	if (deque.size() % 2) {
		straggler = deque.back();
		deque.pop_back();
	}

	// 2nd step: make pairs of the deque elements!
	std::deque<std::pair<int, int>> pairs = makePairs(deque);

	// 3rd step: sort the pairs based on the second element of the pair, in ascending order!
	sortPairs(pairs, (pairs.size() - 1));

	// 4th step: create a sorted sequence from the pairs!
	createSortedSequence(pairs, straggler);
}

std::deque<std::pair<int, int>> PmergeMe::makePairs(std::deque<int> &deque) {

	std::deque<std::pair<int, int>> pairs;
	for (size_t i = 0; i < deque.size(); i+=2) {
		std::pair<int, int> pair = std::minmax(deque[i], deque[i + 1]);
		pairs.push_back(pair);
	}
	return (pairs);
}

void PmergeMe::sortPairs(std::deque<std::pair<int, int>> &pairs, int length) {
	if (length == 0)
		return ;

	// 3rd step: recursively sort the pairs based on the second element of the pair, in ascending order!
	sortPairs(pairs, length - 1);

	std::pair<int, int> pair = pairs[length];
	int i = length - 1;
	while (i >= 0 && pairs[i].second > pair.second) {
		pairs[i + 1] = pairs[i];
		i--;
	}
	pairs[i + 1] = pair;
}

void PmergeMe::createSortedSequence(std::deque<std::pair<int, int>> &pairs, int straggler) {
	deque.clear();
	std::deque<int> pend;

	// 3th step: insert the second element of the pairs into the deque!
	for (size_t i = 0; i < pairs.size(); i++) {
		deque.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	// 4th step: insert at the beginning of the sorted sequence the first element that was paired with the smallest element of the sorted sequence!
	int s1 = pend.front();
	pend.erase(pend.begin());
	deque.insert(deque.begin(), s1);

	// 5th step: if there is a straggler, we need to insert it into the pend sequence!
	if (straggler != -1) {
		pend.push_back(straggler);
	}

	// 6th step: insert the elements of the pend sequence into the sorted sequence with binary search!
	for (int element : pend) {
		size_t position = std::upper_bound(deque.begin(), deque.end(), element) - deque.begin();
		deque.insert(deque.begin() + position, element);
	}
}

/******************************************************************************/
/*								Display Content								  */
/******************************************************************************/

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
