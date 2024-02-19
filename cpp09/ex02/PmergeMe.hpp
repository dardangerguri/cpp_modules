/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/19 18:45:13 by dgerguri         ###   ########.fr       */
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

		void 	sortAndDisplay(char **argv);

		// Input
		void	validateInput(char **argv, std::vector<int> &vector);
		void	validateInput(char **argv, std::deque<int> &deque);
		int		convertStringToInt(std::string str);
		void	checkForDuplicates(std::vector<int> &vector, int number);
		void	checkForDuplicates(std::deque<int> &deque, int number);

		// Vector
		void	sortVector(std::vector<int> &vector);
		std::vector<std::pair<int, int>>	makePairs(std::vector<int> &vector);
		void	sortPairs(std::vector<std::pair<int, int>> &pairs, int length);
		void	createSortedSequence(std::vector<std::pair<int, int>> &pairs, int straggler);

		// Deque
		void	sortDeque(std::deque<int> &deque);
		std::deque<std::pair<int, int>>		makePairs(std::deque<int> &deque);
		void	sortPairs(std::deque<std::pair<int, int>> &pairs, int length);
		void	createSortedSequence(std::deque<std::pair<int, int>> &pairs, int straggler);

		// Display
		void 	displayContent(const std::vector<int>& container);
		void 	displayContent(const std::deque<int>& container);

};

# endif
