/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:33:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/09 15:11:49 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void testZombieHorde(int N, std::string name) {
	std::cout << GRY2 << "🌟 Test with " << N << " zombies named \"" << name << "\":" << RESET << std::endl;
		
	Zombie* horde = zombieHorde(N, name);

	if (horde) {
		for (int i = 0; i < N; ++i) {
			std::cout << CYAN;
			horde[i].announce();
		}
		delete[] horde;
		std::cout << GRNN << "✅ Zombie horde test completed successfully!" << RESET << std::endl;
	} else {
		std::cerr << RED << "❌ Error: Unable to create a horde of " << N << " zombies." << RESET << std::endl;
	}
    
	std::cout << YLLW << "-----------------------------------------" << RESET << std::endl;
}

 
int main()
{
	testZombieHorde(5, "Zombie");
	testZombieHorde(1, "Single Zombie");
	testZombieHorde(0, "No Zombie");
	testZombieHorde(3, "DifferentZombie");
	testZombieHorde(100, "HordeZombie");

	std::cout << BLUE << "============================================================" << RESET << std::endl;
	std::cout << BLUE << "==================== END OF THE TEST =======================" << RESET << std::endl;
	return 0;
}
