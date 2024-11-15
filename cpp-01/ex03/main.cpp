/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/14 17:17:36 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main(){
// {
// 	Weapon club = Weapon("crude spiked club");
// 	HumanA bob("Bob", club);
// 	bob.attack();
// 	club.setType("some other type of club");
// 	bob.attack();
// }
// {
// 	Weapon club = Weapon("crude spiked club");
// 	HumanB jim("Jim");
// 	jim.attack();
// 	jim.setWeapon(club);
// 	jim.attack();
// 	club.setType("some other type of club");
// 	jim.attack();
// }
// 	return 0;
// }

int main() {
 {
        std::cout << BOLD << CYAN << "=== SCENARIO 1: HumanA with a Weapon ===" << RESET << std::endl;
        Weapon club = Weapon("crude spiked club 🪓");
        HumanA bob("Bob", club);
        bob.attack();
        std::cout << LIME << "🛠 Changing weapon type..." << RESET << std::endl;
        club.setType("some other type of club 🏏");
        bob.attack();
    }

    {
        std::cout << BOLD << CYAN << "\n=== SCENARIO 2: HumanB starting without a Weapon ===" << RESET << std::endl;
        Weapon club = Weapon("crude spiked club 🪓");
        HumanB jim("Jim");
        jim.attack();
        std::cout << YLLW << "🔧 Assigning a weapon to Jim..." << RESET << std::endl;
        jim.setWeapon(club);
        jim.attack();
        std::cout << LIME << "🛠 Changing weapon type..." << RESET << std::endl;
        club.setType("some other type of club 🏏");
        jim.attack();
    }

    {
        std::cout << BOLD << CYAN << "\n=== SCENARIO 3: Multiple Humans Sharing the Same Weapon ===" << RESET << std::endl;
        Weapon sword = Weapon("sharp sword ⚔️");
        HumanA alix("Alix", sword);
        HumanB charlie("Charlie");
        charlie.setWeapon(sword);

        alix.attack();
        charlie.attack();

        std::cout << LIME << "🛠 Alix sharpens the sword!" << RESET << std::endl;
        sword.setType("legendary blade 🗡️");
        alix.attack();
        charlie.attack();
    }

    {
        std::cout << BOLD << CYAN << "\n=== SCENARIO 4: HumanB with No Weapon Throughout ===" << RESET << std::endl;
        HumanB dave("Dave");
        dave.attack();
    }

    std::cout << BOLD << RED << "\n=== END OF TESTS ===" << RESET << std::endl;

    return 0;
}
