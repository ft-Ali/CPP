/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:47:31 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/09 11:57:21 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << BLUE + "Zombie created" + RESET << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << RED + "Zombie destroyed" + RESET << std::endl;
	return ;
}

void Zombie::printTest() {
	std::cout << "Test constructor and destructor" << std::endl;
	return ;
}
