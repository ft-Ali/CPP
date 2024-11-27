/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:43:22 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 15:18:09 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << GRNN << "🟢 Animal Default Constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << CYAN << "🐾 Animal Parameterized Constructor called for type: " 
              << YLLW << type << RESET << std::endl;
}

Animal::Animal(const Animal &src): _type(src._type) {
	std::cout << BLUE << "🔄 Animal Copy Constructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
	if (this != &src){	
		_type = src._type;
	 	std::cout << ORNG << "✍️  Animal Copy Assignment Operator called" << RESET << std::endl;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << RED << "🔴 Animal Destructor called" << RESET << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const {
	std::cout << SLVR << "📋 Animal getType called, returning type: " 
              << BLUE << _type << RESET << std::endl;
	return _type;
}
