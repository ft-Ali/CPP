/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:56:43 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 15:03:31 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << GRNN << "🐾 WrongAnimal Default Constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	 std::cout << GRNN << "🐾 WrongAnimal Parametrized Constructor called with type: " 
              << CYAN << type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << BLUE << "🔄 WrongAnimal Copy Constructor called" << RESET << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	std::cout << ORNG << "✍️ WrongAnimal Assignation Operator called" << RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "🔴 WrongAnimal Destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << MAGN << "🔊 WrongAnimal makes a sound: " 
              << GRY1 << "\"WrongAnimal makes a sound\"" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	std::cout << SLVR << "📋 WrongAnimal getType called, returning type: " 
              << CYAN << _type << RESET << std::endl;
	return this->_type;
}
