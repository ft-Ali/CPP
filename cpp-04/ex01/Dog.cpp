/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:50:05 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 17:21:45 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->_brain = new Brain();
	std::cout << GRNN << "🐶 Dog Default Constructor called" << RESET << std::endl;
}

Dog::~Dog() {
	std::cout << RED << "🔴 Dog Destructor called" << RESET << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &src) {
	*this = src;
	std::cout << BLUE << "🔄 Dog Copy Constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	if (this != &src) {
		_type = src._type;
		std::cout << ORNG << "✍️  Dog Copy Assignment Operator called" << RESET << std::endl;
	}
	return *this;
}

void Dog::makeSound() const {
	 std::cout << MAGN << "🔊 Dog Sound: " 
              << GRY1 << "\"Woof Woof\"" << RESET << std::endl;
}

std::string Dog::getType() const {
	 std::cout << SLVR << "📋 Dog getType called, returning type: " 
              << CYAN << _type << RESET << std::endl;
	return _type;
}

void Dog::setIdea(int index, std::string idea) {
	if(idea.empty()){
		std::cout << "🧠 Idea is empty" << std::endl;
		return ;
	}
	if(index < 0 || index > 100) {
		std::cout << "🧠 Invalid index" << std::endl;		
		return ;
	}
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	if(index < 0 || index > 100) {
		std::cout << "🧠 Invalid index" << std::endl;		
		return NULL;
	}
	return _brain->getIdea(index);
}
