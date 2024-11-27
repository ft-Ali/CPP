/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:38:02 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 15:17:53 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	 std::cout << GRNN << "🐱 Cat Default Constructor called" << RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED << "🔴 Cat Destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &src) {
	*this = src;
	std::cout << BLUE << "🔄 Cat Copy Constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	if (this != &src) {	
		_type = src._type;
	 	std::cout << ORNG << "✍️  Cat Copy Assignment Operator called" << RESET << std::endl;
	}
	return *this;
}

void Cat::makeSound() const {
	 std::cout << MAGN << "🔊 Cat Sound: " 
              << GRY1 << "\"Meow Meow\"" << RESET << std::endl;
}

std::string Cat::getType() const {
	std::cout << SLVR << "📋 Cat getType called, returning type: " 
              << CYAN << _type << RESET << std::endl;
	return _type;
}
