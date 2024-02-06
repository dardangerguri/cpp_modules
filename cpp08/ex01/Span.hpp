/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/06 16:30:52 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

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
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:

		unsigned int		N;
		std::vector<int>	v;
};

# endif
