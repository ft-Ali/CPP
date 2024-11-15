/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/15 14:52:31 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed	a;
	Fixed	c;

	Fixed b(a);
	std::cout << "=====================" << std::endl;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << "=====================" << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << "=====================" << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "=====================" << std::endl;
	return (0);
}
