/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:52:50 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 10:32:27 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Color.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <string>
#include <fstream>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(const std::string& type);
		~Weapon();
		void setType(std::string type);
		const std::string& getType();
};



#endif
