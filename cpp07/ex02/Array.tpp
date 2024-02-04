/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/04 19:05:25 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <class T> Array<T>::Array(void) : size(0), array(NULL) {
}

template <class T> Array<T>::Array(unsigned int n) : size(n) {
	this->array = new T[n];
}

template <class T> Array<T>::Array(Array const &copy) : size(copy.size) {
	this->array = new T[this->size];
	for (unsigned int i = 0; i < this->size; i++)
		this->array[i] = copy.array[i];
}

template <class T> Array<T> &Array<T>::operator=(Array const &src) {
	if (this != &src) {
		this->size = src.size;
		delete this->array;
		this->array = new T[this->size];
		for (unsigned int i = 0; i < this->size; i++)
			this->array[i] = src.array[i];
	}
	return (*this);
}

template <class T> Array<T>::~Array(void) {
	if (this->array)
		delete [] this->array;
}

template <class T> T &Array<T>::operator[](unsigned int index) const {
	if (index >= this->size)
		throw Array::OutOfBoundsException();
	return (this->array[index]);
}

template <class T> const char *Array<T>::OutOfBoundsException::what() const throw() {
	return ("Index out of bond!");
}

# endif
