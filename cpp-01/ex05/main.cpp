/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 16:57:33 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << LIME << "🟢 TESTING Debug" << RESET << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
	
    std::cout << CYAN << "🔵 TESTING Info" << RESET << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
	
    std::cout << YLLW << "🟡 TESTING Warning" << RESET << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
	
    std::cout << RED << "🔴 TESTING Error" << RESET << std::endl;
    harl.complain("ERROR");
	std::cout << std::endl;
	
    std::cout << "❓ TESTING Invalid" << std::endl;
    harl.complain("asd");
	
	return 0;
}
