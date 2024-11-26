/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:25:13 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/26 16:08:22 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << GRY1 << "⚙️ " << RESET << GRNN << "[Default Constructor] " << RESET << "A FragTrap has been constructed!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << GRY1 << "🔧 " << RESET << RED << "[Destructor FragTrap] " << RESET << "FragTrap: " << BLUE << this->_name << RESET << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap(const std::string name) {
	std::cout << GRY1 << "✨ " << RESET << CYAN << "[Parameterized Constructor] " << RESET << "Creating FragTrap: " << BLUE << name << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << GRY1 << "🔄 " << RESET << PURP << "[Copy Constructor] " << RESET << "Cloning FragTrap: " << BLUE << src._name << RESET << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	std::cout << GRY1 << "🔄 " << RESET << GOLD << "[Assignment Operator] " << RESET << "Assigning FragTrap: " << BLUE << src._name << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << GRY1 << "🙌 " << RESET << YLLW << "[High Five] " << RESET << "FragTrap: " << BLUE << this->_name << RESET << " is requesting a high five!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	std::cout << GRY1 << "⚔️  " << RESET << GOLD << "[Attack] " << RESET;
	if (this->_energyPoints <= 0) {
		std::cout << YLLW << "FragTrap " << BLUE << this->_name << RESET << RED << " has no energy points left and cannot attack!" << RESET << std::endl;
	}
	else if (this->_hitPoints <= 0) {
		std::cout << YLLW << "FragTrap " << BLUE << this->_name << RESET << RED << " has no hit points left and cannot attack!" << RESET << std::endl;
	}
	else {
		std::cout << BLUE << this->_name << RESET << " attacks " << PINK << target << RESET << ", causing " << RED << this->_attackDamage << RESET << " points of damage !" << std::endl;
						this->_energyPoints--;
	}
	info();
}
