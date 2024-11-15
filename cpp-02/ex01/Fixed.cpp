/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:47:24 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/15 14:55:15 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor (no parameters)
Fixed::Fixed() : _value(0) {
	std::cout << RED << "🚀 Default constructor called" << RESET << std::endl;
}

// Copy constructor (with a reference to a Fixed)
Fixed::Fixed(const Fixed &src) {
	std::cout << RED << "📋 Copy constructor called" << RESET << std::endl;
	*this = src;
}

// Destructor
Fixed::~Fixed() {
	std::cout << RED << "💥 Destructor called" << RESET << std::endl;
}

// Assignation operator overload (with a reference to a Fixed)
Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << RED << "🔄 Assignation operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

// Member functions 
int Fixed::getRawBits(void) const {
	std::cout << RED << "🔍 getRawBits member function called" << RESET << std::endl;
	return (this->_value);
}

// Member functions
void Fixed::setRawBits(int const raw) {
	std::cout << RED << "✏️ setRawBits member function called" << RESET << std::endl;
	this->_value = raw;
}
