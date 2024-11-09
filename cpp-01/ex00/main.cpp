/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:33:29 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/09 13:30:16 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
 
int main()
{
	Zombie* HeapZombie = newZombie("HeapZombie");
	HeapZombie->announce();
	delete HeapZombie;

	randomChump("StackZombie");
	
	return 0;
}
