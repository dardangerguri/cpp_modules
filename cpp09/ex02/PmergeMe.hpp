/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/12 16:55:44 by dgerguri         ###   ########.fr       */
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
# include <fstream>
# include <sstream>
# include <vector>
# include <deque>

class PmergeMe {

	public:

		PmergeMe(char **argv);
		~PmergeMe(void);

	private:

		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &src);

		void	validateInput(char **argv);
		int		checkInt(std::string);
		void	checkDoubles(int number);
		void	sortAlgorithm();
		void	sortVector(std::vector<int> &vector);
		void	combineVectors(std::vector<int> &vector, std::vector<int> &left, std::vector<int> &right);

		std::vector<int> vector;
		std::deque<int> deque;


		void displayContentVector(); //delete
		void displayContentDeque(); //delete



};

# endif
