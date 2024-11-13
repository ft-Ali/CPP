/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:23:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 10:48:17 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon &weapon);
};


#endif
