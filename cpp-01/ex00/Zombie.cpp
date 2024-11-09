/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:47:31 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/09 13:39:26 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << RED + "Zombie " << _name << " is dead" + RESET << std::endl;
}

void Zombie::announce() const {
	std::cout <<  _name << LIME + " BraiiiiiiinnnzzzZ..." + RESET << std::endl;
}
