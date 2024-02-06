/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/06 16:25:17 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(Span const & copy) : N(copy.N), v(copy.v) {}

Span::~Span(void) {}

Span & Span::operator=(Span const & copy) {
	if (this != &copy)
	{
		this->v.clear();
		this->N = copy.N;
		this->v = copy.v;
	}
	return (*this);
}

void	Span::addNumber(int n) {
	if (this->v.size() >= this->N)
		throw Span::FullSpanException();
	this->v.push_back(n);
}

void	Span::addManyNumbers(int nNumbers)
{
	std::srand(std::time(NULL));
	std::vector<int> randomNumbers;
	for (int i = 0; i < nNumbers; i++)
		randomNumbers.push_back(rand());
	if (this->v.size() + randomNumbers.size() > this->N)
		throw FullSpanException();
	this->v.insert(this->v.end(), randomNumbers.begin(), randomNumbers.end());
}

int		Span::shortestSpan(void) {
	if (this->v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int>	tmp(this->v);
	std::sort(tmp.begin(), tmp.end());
	int	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int 	Span::longestSpan(void) {
	if (this->v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int>	tmp(this->v);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

void	Span::displayVector(void) {
	for (unsigned int i = 0; i < this->v.size(); i++)
		std::cout << this->v[i] << " ";
	std::cout << std::endl;
}

const char	*Span::FullSpanException::what() const throw() {
	return ("Span is full");
}

const char	*Span::NoSpanException::what() const throw() {
	return ("Span is empty or contains only one element");
}
