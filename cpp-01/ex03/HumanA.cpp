/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:26:59 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 11:01:46 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << GRY2 << _name << RED + " attacks with his " << _weapon.getType() + RESET << std::endl;
}
