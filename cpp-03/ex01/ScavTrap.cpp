/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:22:46 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/26 16:02:53 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << GRY1 << "⚙️ " << RESET << GRNN << "[Default Constructor] " << RESET << "A ScavTrap has been constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
	std::cout << GRY1 << "🔄 " << RESET << PURP << "[Copy Constructor] " << RESET << "Cloning ScavTrap: " << BLUE << src._name << RESET << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << GRY1 << "💥 " << RESET << RED << "[Destructor ScavTrap] " << RESET << "Destroying ScavTrap: " << BLUE << this->_name << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	std::cout << GRY1 << "🔄 " << RESET << GOLD << "[Assignment Operator] " << RESET << "Assigning ClapTrap: " << BLUE << src._name << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << GRY1 << "✨ " << RESET << CYAN << "[Parameterized Constructor] " << RESET << "Creating ScavTrap: " << BLUE << name << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

void ScavTrap::attack(const std::string& target){
	std::cout << GRY1 << "⚔️ " << RESET << YLLW << "[ScavTrap] " << RESET << "ScavTrap " << BLUE << this->_name << RESET << " attacks " << BLUE << target << RESET << ", causing " << RED << this->_attackDamage << RESET << " points of damage!" << std::endl;
	// std::cout << this->_attackDamage << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << GRY1 << "🛡 " << RESET << YLLW << "[ScavTrap] " << RESET << "ScavTrap " << BLUE << this->_name << RESET << " has entered Gate Keeper mode!" << std::endl;
}


