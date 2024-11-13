/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:28:09 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 10:56:00 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::attack() const {
	if(this->_weapon)
		std::cout << EMRD << "🗡️ " << _name << RED << " attacks with his " << CYAN << _weapon->getType() << RESET << std::endl;
	else
		std::cout << YLLW << "👊 " << _name << RED << " attacks with his bare hands" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
