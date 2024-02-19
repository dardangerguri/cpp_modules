/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/19 09:28:32 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"


# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <chrono>

class PmergeMe {

	public:

		PmergeMe(char **argv);
		~PmergeMe(void);

	private:

		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &src);

		std::vector<int> vector;
		std::deque<int> deque;

		void	validateInput(char **argv);
		int		convertStringToInt(std::string str);
		void	checkForDuplicates(int number);

		void 	sortAndDisplay();

		void	sortVector(std::vector<int> &vector);
		void	sortDeque(std::deque<int> &deque);
		void	mergeVectors(std::vector<int> &vector, std::vector<int> &left, std::vector<int> &right);
		void	mergeDeques(std::deque<int> &deque, std::deque<int> &left, std::deque<int> &right);

		void 	displayContent(const std::vector<int>& container);
		void 	displayContent(const std::deque<int>& container);


		std::vector<std::pair<int, int>> makePairs(std::vector<int> &vector);
		// std::vector<std::pair<int, int>> sortPairs(std::vector<std::pair<int, int>> &pairs, int length);
		void sortPairs(std::vector<std::pair<int, int>> &pairs, int length);
		void createSortedSequence(std::vector<std::pair<int, int>> &pairs);

		std::vector<int> buildJacobInsertionSequence(std::vector<int> pend, int length);
		int jacobsthal(int n);


};

# endif
