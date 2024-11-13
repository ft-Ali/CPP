/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:12 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 10:29:52 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"


class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;

	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif
