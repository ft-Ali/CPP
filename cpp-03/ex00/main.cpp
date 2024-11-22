/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/22 11:56:19 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Ficelo");
	ClapTrap b("Corbac");
	
	
	std::cout << "----------------" << std::endl;
	a.attack("Corbac");
	b.attack("Ficelo");
	std::cout << "----------------" << std::endl;
	
}
