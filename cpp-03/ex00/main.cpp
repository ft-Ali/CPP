/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/25 18:36:07 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main() {
    std::cout << CLRALL << "🤖 Welcome to the ClapTrap Battle Simulator! 🤖" << std::endl;

    // Création des ClapTraps
    ClapTrap claptrap1("TrapMaster");
    ClapTrap claptrap2("RoboWarrior");

    // Afficher l'état initial
    std::cout << "\n🌟 Initial State 🌟" << std::endl;
    claptrap1.info();
    claptrap2.info();

    // Simulation de bataille
    std::cout << "\n⚔️ Round 1: TrapMaster attacks RoboWarrior!" << std::endl;
    claptrap1.attack("RoboWarrior");
    claptrap2.takeDamage(5); // Supposons une valeur fixe de dégâts

    std::cout << "\n⚔️ Round 2: RoboWarrior strikes back!" << std::endl;
    claptrap2.attack("TrapMaster");
    claptrap1.takeDamage(7); // Supposons une autre valeur fixe de dégâts

    std::cout << "\n🔧 Round 3: TrapMaster repairs itself!" << std::endl;
    claptrap1.beRepaired(5);

    std::cout << "\n⚔️ Round 4: RoboWarrior attempts another attack!" << std::endl;
    claptrap2.attack("TrapMaster");

    // Afficher l'état final
    std::cout << "\n🏁 Final State 🏁" << std::endl;
    claptrap1.info();
    claptrap2.info();

    std::cout << "\n🎉 Game Over! Thanks for playing! 🎉" << std::endl;

    return 0;
}

