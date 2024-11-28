/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:51:49 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/28 10:01:04 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << GRNN << "🧠 Brain Default Constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "🧠 Empty Idea";
	}
}

Brain::Brain(const Brain &src) {
	 for (int i = 0; i < 100; i++) {
		_ideas[i] = src._ideas[i];
    }
	std::cout << BLUE << "🔄 Brain Copy Constructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &src) {
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = src._ideas[i];
		}
		std::cout << ORNG << "✍️  Brain Copy Assignment Operator called" << RESET << std::endl;
	}
	return *this;
}

Brain::~Brain() {
	std::cout << RED << "🔴 Brain Destructor called" << RESET << std::endl;
}

void Brain::setIdea(int index, std::string idea) {
	if(idea.empty()){
		std::cout << "🧠 Idea is empty" << std::endl;
		return ;
	}
	if(index < 0 || index > 100){
		std::cout << "🧠 Invalid index" << std::endl;		
		return ;
	}
	_ideas[index] = idea;
	std::cout << "🧠 Idea set at index " << index << ": " << idea << std::endl;
}

std::string Brain::getIdea(int index) const {
	
	std::cout << "🧠 Idea at index " << index << ": " << _ideas[index] << std::endl;
	
	if(index < 0 || index > 100) {
		std::cout << "🧠 Invalid index" << std::endl;		
		return NULL;
	}
	return _ideas[index];
}
