/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/26 15:16:28 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("ClapTrap");
	ClapTrap clap2("ClapTrap2");
	ClapTrap clap3("ClapTrap3");

	clap.info();
	clap2.info();
	clap3.info();

	clap.attack("ClapTrap2");
	clap2.takeDamage(4);
	clap2.beRepaired(1);

	clap.info();
	clap2.info();
	clap3.info();

	return (0);
}

