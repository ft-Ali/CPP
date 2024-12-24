/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:37:07 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/24 14:37:04 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"


Cure::Cure() : AMateria("cure") {
}

Cure::Cure(Cure const &src) : AMateria(src) {
	
}

Cure &Cure::operator=(const Cure &src) {
	if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure() {
}
