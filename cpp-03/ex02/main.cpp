/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/26 16:07:11 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("ClapTrap");
    ScavTrap scav("ScavTrap");
    FragTrap frag("FragTrap");

    clap.info();
    scav.info();
    frag.info();
    clap.attack("ScavTrap");
    clap.takeDamage(0);

    scav.info();
    scav.attack("ClapTrap");
    clap.takeDamage(20);
    scav.guardGate();
    clap.beRepaired(5);
    clap.info();
    scav.info();

    frag.highFivesGuys();
    clap.info();
    scav.info();
    frag.info();
    return 0;
}
