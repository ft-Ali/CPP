/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:06:09 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/01 16:00:18 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


Test::Test(void) {
	std::cout << BLUE << "[Test constructor called]" << RESET << std::endl;
	return;
}

Test::~Test(void) {
	std::cout << RED << "[Test destructor called]" << RESET << std::endl;
	return;
}

void Test::printColor(std::string color) {
	std::cout << color << "Hello World!" << RESET << std::endl;
}
void Test::printUpper(std::string str) {

		for (int i = 0; str[i]; i++){
			
			std::cout << YELLOW << (char)toupper(str[i]) << RESET;
		}
		std::cout << std::endl;
		return;
}

int main(void)
{
	Test test;

	test.printColor(CYAN);
	test.printUpper("ceci est un test");
	

	return (0);
}
