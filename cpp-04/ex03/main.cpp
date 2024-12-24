/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:27:11 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/24 15:29:26 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"


/* int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
} */

int main(void) {
    // === INITIAL SETUP ===
    std::cout << BOLD << BLUE << "🌌 Creating Materia Source..." << RESET << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << BOLD << YLLW << "👤 Creating Character: \"me\"" << RESET << std::endl;
    ICharacter *me = new Character("me");

    // SCENARIO 1: Full Inventory Test
    std::cout << BOLD << CYAN << "=== SCENARIO 1: Full Inventory Test ===" << RESET << std::endl;

    AMateria *tmp1 = src->createMateria("ice");
    AMateria *tmp2 = src->createMateria("cure");
    AMateria *tmp3 = src->createMateria("ice");
    AMateria *tmp4 = src->createMateria("cure");
    AMateria *tmp5 = src->createMateria("ice"); // Exceeds inventory limit

    std::cout << BOLD << GRNN << "🛠️ Equipping 4 Materias..." << RESET << std::endl;
    me->equip(tmp1);
    me->equip(tmp2);
    me->equip(tmp3);
    me->equip(tmp4);

    std::cout << BOLD << RED << "⚠️ Attempting to equip a 5th Materia (should fail)..." << RESET << std::endl;
    me->equip(tmp5);

    std::cout << BOLD << MAGN << "✨ Using all equipped Materias..." << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        me->use(i, *me);
    }

    // SCENARIO 2: Unequipping and Re-equipping Materia
    std::cout << BOLD << CYAN << "=== SCENARIO 2: Unequipping and Re-equipping ===" << RESET << std::endl;

    std::cout << BOLD << ORNG << "🔄 Unequipping Materia at index 1..." << RESET << std::endl;
    me->unequip(1);
    me->use(1, *me); // Trying to use an empty slot

    AMateria *tmp6 = src->createMateria("cure");
    std::cout << BOLD << GRNN << "🛠️ Re-equipping Materia at index 1..." << RESET << std::endl;
    me->equip(tmp6);
    me->use(1, *me);

    // SCENARIO 3: Character Interaction
    std::cout << BOLD << CYAN << "=== SCENARIO 3: Character Interaction ===" << RESET << std::endl;

    std::cout << BOLD << PURP << "👤 Creating Character: \"bob\"" << RESET << std::endl;
    ICharacter *bob = new Character("bob");

    std::cout << BOLD << MAGN << "✨ Using Materias on bob..." << RESET << std::endl;
    me->use(0, *bob);
    me->use(3, *bob);

    AMateria *tmp7 = src->createMateria("ice");
    bob->equip(tmp7);
    bob->use(0, *me);

    // SCENARIO 4: Advanced Inventory Management
    std::cout << BOLD << CYAN << "=== SCENARIO 4: Advanced Inventory Management ===" << RESET << std::endl;

    AMateria *tmp8 = src->createMateria("cure");
    AMateria *tmp9 = src->createMateria("ice");
    AMateria *tmp10 = src->createMateria("cure");

    std::cout << BOLD << GRNN << "🛠️ Equipping Materias for bob..." << RESET << std::endl;
    bob->equip(tmp8);
    bob->equip(tmp9);
    bob->equip(tmp10);

    bob->unequip(1);
    AMateria *tmp11 = src->createMateria("ice");
    bob->equip(tmp11);

    std::cout << BOLD << MAGN << "✨ Using Materias after inventory adjustment..." << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        bob->use(i, *me);
    }

    // SCENARIO 5: Cleanup Test
    std::cout << BOLD << CYAN << "=== SCENARIO 5: Cleanup and Memory Test ===" << RESET << std::endl;

    std::cout << BOLD << RED << "🗑️ Cleaning up Materias and Characters..." << RESET << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << BOLD << GRY2 << "✅ Program completed successfully!" << RESET << std::endl;
    return 0;
}
