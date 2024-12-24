/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:56:30 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/24 15:28:21 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : _materiasCount(0) {
	
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}


MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (this->_materias[i] != NULL) {
				delete this->_materias[i];
			}
			if (src._materias[i] != NULL) {
				this->_materias[i] = src._materias[i]->clone();
			} else {
				this->_materias[i] = NULL;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] != NULL) {
			delete _materias[i];
			_materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m || _materiasCount >= 4) {
        delete m; // Supprime si l'inventaire est plein
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (!_materias[i]) {
            _materias[i] = m; // Pas besoin de `clone` ici
            _materiasCount++;
            break;
        }
    }
}


AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] != NULL && _materias[i]->getType() == type) {
			return _materias[i]->clone();
		}
	}
	return NULL;
}



