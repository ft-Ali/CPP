/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:37:21 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/09 15:02:47 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Color.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <string>
#include <fstream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void setName(std::string name);
		void announce();
};

	Zombie* zombieHorde(int N, std::string name);
	



#endif
