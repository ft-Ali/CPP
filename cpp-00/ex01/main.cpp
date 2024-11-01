/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:06:09 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/01 15:45:21 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


Test::Test(void)
{
	std::cout << "Test constructor called" << std::endl;
	return;
}

Test::~Test(void)
{
	std::cout << "Test destructor called" << std::endl;
	return;
}

void Test::printColor(std::string color)
{
	std::cout << color << "Hello World!" << RESET << std::endl;
}


int main(void)
{
	Test test;

	test.printColor(RED);
}
