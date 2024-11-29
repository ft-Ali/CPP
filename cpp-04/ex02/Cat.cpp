/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:38:02 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/29 13:27:29 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain()) {
	std::cout << GRNN << "🐱 Cat Default Constructor called" << RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED << "🔴 Cat Destructor called" << RESET << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain(*src._brain)){
    std::cout << "Cat: Copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &src){
	if (this != &src) {
		Animal::operator=(src);
		delete _brain;
		_brain = new Brain(*src._brain);
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

std::string Cat::getIdea(int index) const {
	if(index < 0 || index > 100) {
		std::cout << "🧠 Invalid index" << std::endl;		
		return NULL;
	}
	return _brain->getIdea(index);
}

void Cat::setIdea(int index, std::string idea) {
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

