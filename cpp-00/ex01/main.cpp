/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:06:09 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/01 15:56:25 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


Test::Test(void) {
	std::cout << "Test constructor called" << std::endl;
	return;
}

Test::~Test(void) {
	std::cout << "Test destructor called" << std::endl;
	return;
}

void Test::printColor(std::string color) {
	std::cout << color << "Hello World!" << RESET << std::endl;
	std::cout << color << "Yo la street" << RESET <<  std::endl;
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

	test.printColor(RED);
	test.printColor(CYAN);
	test.printUpper("ceci est un test");
	

	return (0);
}
