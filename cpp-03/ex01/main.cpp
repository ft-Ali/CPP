/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/26 16:04:45 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
    ClapTrap clap("ClapTrap");
    ScavTrap scav("ScavTrap");

    clap.info();
    scav.info();
    clap.attack("ScavTrap");
    clap.takeDamage(0);

    scav.info();
    scav.attack("ClapTrap");
    clap.takeDamage(20);
    scav.guardGate();
    clap.beRepaired(5);
    clap.info();
    scav.info();

    return (0);
}
