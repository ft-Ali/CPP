/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 17:29:56 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Harl.hpp"

int main(int c, char **v) {
	Harl harl;

    if(c != 2) {
        std::cerr << RED << "Harl waiting for :  DEBUG, INFO, WARNING, ERROR or ask him whatever you want " << RESET << std::endl;
        return 1;
    }
    harl.complain(v[1]);
	
	return 0;
}
