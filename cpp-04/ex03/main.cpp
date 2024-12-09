/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:27:11 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/04 09:39:56 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"


int main(void) {
    // std::cout << CLRALL;


    std::cout << BOLD << BLUE << "🌌 Creating Materia Source..." << RESET << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << BOLD << YLLW << "👤 Creating Character: \"me\"" << RESET << std::endl;
    ICharacter *me = new Character("me");


    std::cout << BOLD << GRNN << "❄️  Creating and equipping Ice Materia..." << RESET << std::endl;
    AMateria *tmp = src->createMateria("ice");
    me->equip(tmp);

    std::cout << BOLD << CYAN << "🩹 Creating and equipping Cure Materia..." << RESET << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);


    std::cout << BOLD << PURP << "👤 Creating Character: \"bob\"" << RESET << std::endl;
    ICharacter *bob = new Character("bob");

    std::cout << BOLD << MAGN << "✨ Using Materias on bob..." << RESET << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

 
    std::cout << BOLD << ORNG << "🔄 Unequipping Ice Materia and re-equipping it..." << RESET << std::endl;
    me->unequip(0);
    me->equip(tmp);


    std::cout << BOLD << RED << "🗑️ Cleaning up..." << RESET << std::endl;
    delete bob;
    delete me;
    delete src;
	delete tmp;


    std::cout << BOLD << GRY2 << "✅ Program completed successfully!" << RESET << std::endl;
    return 0;
}
