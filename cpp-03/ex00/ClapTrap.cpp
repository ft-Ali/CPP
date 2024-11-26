/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/26 16:21:02 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << GRY1 << "⚙️ " << RESET << GRNN << "[Default Constructor] " << RESET << "A ClapTrap has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) {
	std::cout << GRY1 << "✨ " << RESET << CYAN << "[Parameterized Constructor] " << RESET << "Creating ClapTrap: " << BLUE << name << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << GRY1 << "🔄 " << RESET << PURP << "[Copy Constructor] " << RESET << "Cloning ClapTrap: " << BLUE << src._name << RESET << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << GRY1 << "🔄 " << RESET << GOLD << "[Assignment Operator] " << RESET << "Assigning ClapTrap: " << BLUE << src._name << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << GRY1 << "💥 " << RESET << RED << "[Destructor] " << RESET << "Destroying ClapTrap: " << BLUE << this->_name << RESET << std::endl;
}

void ClapTrap::info() {
	std::cout << "=================================================" << std::endl;
	std::cout << GRY1 << "🔎 " << RESET << CYAN << "[Info] " << RESET << "ClapTrap Details:" << std::endl;
	std::cout << "  " << MAGN << "Name: " << RESET << BLUE << this->_name << RESET << std::endl;
	std::cout << "  " << YLLW << "Hit Points: " << RESET << GRNN << this->_hitPoints << RESET << std::endl;
	std::cout << "  " << LIME << "Energy Points: " << RESET << GRNN << this->_energyPoints << RESET << std::endl;
	std::cout << "  " << ORNG << "Attack Damage: " << RESET << RED << this->_attackDamage << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << GRY1 << "⚔️  " << RESET << GOLD << "[Attack] " << RESET;
	if (this->_energyPoints <= 0) {
		std::cout << RED << "ClapTrap " << BLUE << this->_name << RESET << RED << " has no energy points left and cannot attack!" << RESET << std::endl;
	}
	else if (this->_hitPoints <= 0) {
		std::cout << RED << "ClapTrap " << BLUE << this->_name << RESET << RED << " has no hit points left and cannot attack!" << RESET << std::endl;
	}
	else {
		std::cout << BLUE << this->_name << RESET << " attacks " << PINK << target << RESET << ", causing " << RED << this->_attackDamage << RESET << " points of damage !" << std::endl;
						this->_energyPoints--;
	}
	info();
}

void ClapTrap::takeDamage(unsigned int amount) {
	if((int)amount < 0) {
		std::cout << RED << "ClapTrap " << BLUE << this->_name << RESET << RED << " cannot take negative damage!" << RESET << std::endl;
		return ;
	}
	std::cout << GRY1 << "🛡️ " << RESET << RED << "[Take Damage] " << RESET;
	if (this->_hitPoints <= 0) {
		std::cout << RED << "ClapTrap " << BLUE << this->_name << RESET << RED << " has no hit points left and cannot take any more damage!" << RESET << std::endl;
	}
	else {
		std::cout << BLUE << this->_name << RESET << " takes " << RED << amount << RESET << " points of damage !" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0;
	}
	info();
}

void ClapTrap::beRepaired(unsigned int amount) {
	if((int)amount < 0) {
		std::cout << RED << "ClapTrap " << BLUE << this->_name << RESET << RED << " cannot take negative repair!" << RESET << std::endl;
		return ;
	}
	std::cout << GRY1 << "🔧 " << RESET << GRNN << "[Be Repaired] " << RESET;
	if (this->_hitPoints >= 10) {
		std::cout << RED << "ClapTrap " << BLUE << this->_name << RESET << RED << " has full hit points and cannot be repaired!" << RESET << std::endl;
	}
	else {
		std::cout << BLUE << this->_name << RESET << " is being repaired for " << GRNN << amount << RESET << " points !" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	// info();
}
