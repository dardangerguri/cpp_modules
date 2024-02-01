/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/01 13:35:05 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class Span {

	public:

		Span(void);
		Span(unsigned int N);
		Span(Span const & copy);
		~Span(void);

		Span & operator=(Span const & copy);

		void	addNumber(int n);
		void	addManyNumbers(int nNumbers);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	displayVector(void);

		class FullSpanException : public std::exception {
			public:
				const char* what() const throw() {
					return "Span is full";
				}
		};

		class NoSpanException : public std::exception {
			public:
				const char* what() const throw() {
					return "Span is empty or contains only one element";
				}
		};

	private:

		unsigned int		N;
		std::vector<int>	v;
};

# endif
