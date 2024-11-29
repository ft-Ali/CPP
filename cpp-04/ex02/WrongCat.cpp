/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:57:33 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 15:00:59 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << GRNN << "🐾 WrongCat Default Constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) {
	std::cout << BLUE << "🔄 WrongCat Copy Constructor called" << RESET << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	 std::cout << ORNG << "✍️ WrongCat Assignation Operator called" << RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << RED << "🔴 WrongCat Destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << MAGN << "🔊 WrongCat makes a sound: " 
              << GRY1 << "\"WrongCat makes a sound\"" << RESET << std::endl;
}
