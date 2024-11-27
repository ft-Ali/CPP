/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:27:11 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 15:19:43 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main(void) {
	std::cout << CLRALL;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete i;
	delete j;
	return (0);
}

// int main(void) {
// 	std::cout << CLRALL;
// 	std::cout << BOLD << YLLW << "🐾 Animal Simulation Program 🐾" << RESET << std::endl;

// 	std::cout << BOLD << GRNN << "\n🟢 Creating Animals...\n" << RESET;
// 	const Animal *meta = new Animal();
// 	const Animal *j = new Dog();
// 	const Animal *i = new Cat();

// 	const WrongAnimal *wrongMeta = new WrongAnimal();
// 	const WrongAnimal *wrongCat = new WrongCat();

// 	std::cout << BOLD << BLUE << "\n🔍 Animal Details\n" << RESET;
    
// 	std::cout << CYAN << "Type of j (Dog): " << RESET << j->getType() << std::endl;
// 	std::cout << CYAN << "Type of i (Cat): " << RESET << i->getType() << std::endl;
// 	std::cout << CYAN << "Type of wrongCat (WrongCat): " << RESET << wrongCat->getType() << std::endl;
// 	std::cout << CYAN << "Type of wrongMeta (WrongAnimal): " << RESET << wrongMeta->getType() << std::endl;

// 	std::cout << BOLD << MAGN << "\n🔊 Animal Sounds\n" << RESET;
    
// 	std::cout << GRY1 << "i (Cat) makes sound: " << RESET;
// 	i->makeSound();

// 	std::cout << GRY1 << "j (Dog) makes sound: " << RESET;
//     j->makeSound();

// 	std::cout << GRY1 << "meta (Animal) makes sound: " << RESET;
// 	meta->makeSound();

// 	std::cout << GRY1 << "wrongCat (WrongCat) makes sound: " << RESET;
// 	wrongCat->makeSound();

// 	std::cout << GRY1 << "wrongMeta (WrongAnimal) makes sound: " << RESET;
// 	wrongMeta->makeSound();

// 	std::cout << BOLD << RED << "\n🗑️ Cleaning up (Destructors)\n" << RESET;

// 	delete meta;
// 	delete j;
// 	delete i;
// 	delete wrongMeta;
// 	delete wrongCat;

// 	std::cout << BOLD << GRNN << "\n✅ Program finished successfully!" << RESET << std::endl;

// 	return 0;
// }

