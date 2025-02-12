/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:37:21 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/09 14:44:13 by alsiavos         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		void announce();
};

	Zombie* newZombie(std::string name);
	void randomChump(std::string name);


#endif
