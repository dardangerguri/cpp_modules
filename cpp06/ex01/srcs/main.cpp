/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:33:03 by dardangergu       #+#    #+#             */
/*   Updated: 2024/01/19 18:03:47 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	std::cout << RED "Creating data:" RESET << std::endl;
	Data	d;
	d.string = "Hi, I'm Cracked!";
	d.number = 10;
	d.character = 'C';
	d.flag = true;

	std::cout << "Data address: " << &d << std::endl;
	std::cout << "Data number: " << d.number << std::endl;
	std::cout << "Data string: " << d.string << std::endl;
	std::cout << "Data char: " << d.character << std::endl;
	std::cout << "Data bool: " << d.flag << std::endl;
	std::cout << std::endl;

	std::cout << GREEN "Serializing:" RESET << std::endl;
	uintptr_t	ptr = Serializer::serialize(&d);

	std::cout << "Serialized uintptr: " << ptr << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "Deserializing:" RESET << std::endl;
	Data	*convertion = Serializer::deserialize(ptr);

	std::cout << "Deserialized address: " << convertion << std::endl;
	std::cout << "Deserialized data number: " << convertion->number << std::endl;
	std::cout << "Deserialized data string: " << convertion->string << std::endl;
	std::cout << "Deserialized data char: " << convertion->character << std::endl;
	std::cout << "Deserialized data bool: " << convertion->flag << std::endl;
}
