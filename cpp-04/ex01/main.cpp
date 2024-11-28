/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:27:11 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/28 11:38:26 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main() {
// const Animal* j = new Dog();
// const Animal* i = new Cat();

// j->makeSound(); // will output the cat sound!
// i->makeSound();



// delete j; //should not create a leak
// delete i;

// return 0;
// }

int	main(void)
{
	Animal	*animals[10];
	Cat		cat1;
	Cat		cat2;
	Dog		dog1;
	Dog		dog2;

	std::cout << CLRALL << BOLD << YLLW << "🐾 Welcome to the Animal Brain Simulation! 🐾\n" << RESET;
	std::cout << BOLD << GRNN << "\n🟢 Creating a pack of Animals...\n" << RESET;
	for (int i = 0; i < 5; ++i)
	{
		animals[i] = new Dog();
		animals[i + 5] = new Cat();
	}
	std::cout << BOLD << RED << "\n🗑️ Deleting the Animals...\n" << RESET;
	for (int i = 0; i < 10; ++i) {
		delete animals[i];
	}
	
	std::cout << BOLD << BLUE << "\n🔄 Deep Copy Test for Cat 🐱\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		cat1.setIdea(i, "🐭 Catch the mouse!");
		cat2.setIdea(i, "☀️ Bask in the sun!");
	}
	
	std::cout << CYAN << "\n✨ Ideas in Cat1 before copy:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << CYAN << "Idea " << i << ": " << cat1.getIdea(i) << RESET << std::endl;
	}
	
	std::cout << MAGN << "\n✨ Ideas in Cat2 before copy:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << MAGN << "Idea " << i << ": " << cat2.getIdea(i) << RESET << std::endl;
	}
	
	cat1 = cat2;
	
	std::cout << CYAN << "\n✨ Ideas in Cat1 after deep copy:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << CYAN << "Idea " << i << ": " << cat1.getIdea(i) << RESET << std::endl;
	}
	
	for (int i = 0; i < 5; i++) {
		cat2.setIdea(i, "🌟 Independent idea in Cat2!");
	}
	
	std::cout << MAGN << "\n✨ Ideas in Cat1 after modifying Cat2:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << CYAN << "Idea " << i << ": " << cat1.getIdea(i) << RESET << std::endl;
	}
	
	std::cout << MAGN << "\n✨ Ideas in Cat2 after modification:\n" << RESET;
	
	for (int i = 0; i < 5; i++)	{
		std::cout << MAGN << "Idea " << i << ": " << cat2.getIdea(i) << RESET << std::endl;
	}
	
	std::cout << BOLD << BLUE << "\n🔄 Deep Copy Test for Dog 🐶\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		dog1.setIdea(i, "🦴 Chew the bone!");
		dog2.setIdea(i, "🐕 Chase the car!");
	}
	
	std::cout << CYAN << "\n✨ Ideas in Dog1 before copy:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << CYAN << "Idea " << i << ": " << dog1.getIdea(i) << RESET << std::endl;
	}
	
	std::cout << MAGN << "\n✨ Ideas in Dog2 before copy:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << MAGN << "Idea " << i << ": " << dog2.getIdea(i) << RESET << std::endl;
	}
	
	dog2 = dog1;
	
	std::cout << MAGN << "\n✨ Ideas in Dog2 after deep copy:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << MAGN << "Idea " << i << ": " << dog2.getIdea(i) << RESET << std::endl;
	}
	
	for (int i = 0; i < 5; i++) {
		dog1.setIdea(i, "🌟 Independent idea in Dog1!");
	}
	
	std::cout << CYAN << "\n✨ Ideas in Dog2 after modifying Dog1:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << MAGN << "Idea " << i << ": " << dog2.getIdea(i) << RESET << std::endl;
	}
	
	std::cout << CYAN << "\n✨ Ideas in Dog1 after modification:\n" << RESET;
	
	for (int i = 0; i < 5; i++) {
		std::cout << CYAN << "Idea " << i << ": " << dog1.getIdea(i) << RESET << std::endl;
	}
	std::cout << BOLD << GRNN << "\n✅ Simulation completed without errors!\n" << RESET;
	return (0);
}
/**
 * Shallow copy :
 * Copie uniquement les pointeurs, pas les données pointées.

	* les deux objets pointent vers la même zone mémoire dynamique une modification affecte les deux objets.
 * Probleme, si on delete un objet,
	l'autre objet pointe vers une zone mémoire qui n'existe plus.
 *
 *
 * Deep copy :
 * Duplique entierement l'objet, les données pointées sont dupliquées.
 * si un objet a un pointeur vers des ressources dynamiques,
	une nouvelle copie de cette ressource est créée.
 * Resultat, les deux objets sont indépendants.
 */
