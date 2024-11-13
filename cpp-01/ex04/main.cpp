/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 14:50:27 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Sed.hpp"

int main(int c, char **v) {

	if(c != 4) {
		std::cout << RED << "Usage: " << v[0] << " <file> <s1> <s2>" << RESET << std::endl;
		return (0);
	}
	else {

		if (!is_valid(v[1], v[2], v[3])) {
			std::cerr << RED << "Error: Unable to replace string." << RESET << std::endl;
			return (1);
		}
		std::cout << GRNN << "String replaced successfully." << RESET << std::endl;
	}
	return (0);
}
