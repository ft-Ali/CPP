/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:24:43 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 17:33:59 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::_debug() {
	std::cout << LIME << "🐞 DEBUG: " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RESET << std::endl;
}

void Harl::_info() {
	std::cout << CYAN << "ℹ️ INFO: " << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void Harl::_warning() {
	std::cout << YLLW << "⚠️ WARNING: " << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void Harl::_error() {
	std::cout << RED << "❌ ERROR: " << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*complaints[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while( i < 4) {
		if(level == levels[i]) {
			break ;
		}
		i++;
	}
	switch(i) {
		case 0:
			(this->*complaints[0])();
			break ;
		case 1:
			(this->*complaints[1])();
			break ;
		case 2:
			(this->*complaints[2])();
			break ;
		case 3:
			(this->*complaints[3])();
			break ;
	
	default:
		std::cerr << RED << "Probably complaining about insignificant problems" << RESET << std::endl;
	}
}
