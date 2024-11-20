/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/20 17:29:42 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()  {
	std::cout << "contructor" << std::endl;
}

ClapTrap::~ClapTrap()  {
	std::cout << "destructor" << std::endl;
}


void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
		