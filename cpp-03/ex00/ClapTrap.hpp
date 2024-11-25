/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:16:39 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/25 18:35:12 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


# include "Color.hpp"
# include <fstream>
# include <iostream>
# include <string>

class ClapTrap {
	private:
		std::string _name;
		int _hitPoints; 
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string name); // Constructor
		ClapTrap(const ClapTrap &src); // Copy constructor
		ClapTrap &operator=(const ClapTrap &src); // Assignment operator
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void info();

};



#endif
