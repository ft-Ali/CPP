/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:33:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/09 13:34:31 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
 
int main()
{
	Zombie* HeapZombie = newZombie("HeapZombie");
	HeapZombie->announce();
	delete HeapZombie;
	
	std::cout << std::endl;
	randomChump("StackZombie");
	return 0;
}
