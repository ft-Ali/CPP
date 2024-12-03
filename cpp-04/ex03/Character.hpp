/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:41:20 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/03 17:17:14 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Color.hpp"
#include <iomanip>

class Character : public ICharacter {
	private:
		AMateria* _unequiped[4];
		std::string _name;
		AMateria* _inventory[4];
	public:
		Character(std::string const & name);
		Character(const Character &src);
		Character &operator=(const Character &src);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		bool inventoryFull();
		void use(int idx, ICharacter& target);
		virtual ~Character();
		void clearUnequipped();
};


#endif
