/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:56:25 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 10:36:08 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::~Weapon() {
}

Weapon::Weapon(const std::string &type) : _type(type) {
}

const std::string& Weapon::getType()  {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}

