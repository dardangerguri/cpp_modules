/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/01/25 18:08:05 by dardangergu      ###   ########.fr       */
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