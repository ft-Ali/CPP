/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/12 11:57:16 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include <iomanip>
#include <iostream>

int main() {
	
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << GRY1 + "String: " + RESET << str << std::endl;
	std::cout << GRY1 + "Address of the string: " + RESET << &str << std::endl;
	std::cout << YLLW << "-----------------------------------------" << RESET << std::endl;
	std::cout << SLVR + "Address of the stringPTR: " + RESET << stringPTR << std::endl;
	std::cout << SLVR + "Address of the stringREF: " + RESET << &stringREF << std::endl;

	return (0);
}
