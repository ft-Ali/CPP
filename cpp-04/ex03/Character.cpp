/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:47:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/24 15:34:29 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Character::Character() {
// }

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
		_unequiped[i] = NULL;
	}
}

Character::Character(const Character &src) {
    _name = src._name;
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i] != NULL) {
            _inventory[i] = src._inventory[i]->clone(); // Clone chaque Materia
        } else {
            _inventory[i] = NULL;
        }
        if (src._unequiped[i] != NULL) {
            _unequiped[i] = src._unequiped[i]->clone(); // Clone aussi `unequiped`
        } else {
            _unequiped[i] = NULL;
        }
    }
}


Character &Character::operator=(const Character &src) {
	if (this != &src) {
		_name = src._name;
		for (int i = 0; i < 4; i++) {
			_inventory[i] = src._inventory[i];
			_unequiped[i] = src._unequiped[i];
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

bool Character::inventoryFull() {
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) 
			return false;
    }
    return true;
}

void Character::equip(AMateria* m) {
    if (!m) {
		std::cout << "No materia to equip" << std::endl;
		return;
	}
	if (inventoryFull()) {
		std::cout << "Inventory is full cannot equipe new materia !" << std::endl;
		delete m;
		return;
	}
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !_inventory[idx]) {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == _inventory[idx]) {
            _unequiped[idx] = _inventory[idx];
            _inventory[i] = NULL;
            return;
        }
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !_inventory[idx]) {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}


void Character::clearUnequipped() {
	for (int i = 0; i < 4; i++) {
		if (_unequiped[i] != NULL) {
			delete _unequiped[i];
			_unequiped[i] = NULL;
			}
		}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
		}
		if (_unequiped[i] != NULL) {
			delete _unequiped[i];
		}
	}
}

