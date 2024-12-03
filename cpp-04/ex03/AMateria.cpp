/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:02:50 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/03 16:34:05 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
}

std::string const & AMateria::getType() const {
	return _type;
}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src) {
	if (this == &src) {
		return *this;
	}
	_type = src._type;
	return *this;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	
}

AMateria::~AMateria() {
}
