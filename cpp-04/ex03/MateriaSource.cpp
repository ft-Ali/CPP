/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:56:30 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/03 16:41:42 by alsiavos         ###   ########.fr       */
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
		_materiasCount = src._materiasCount;
		for (int i = 0; i < 4; i++) {
			_materias[i] = src._materias[i];
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
    if (!m || _materiasCount >= 4) 
		return;
    for (int i = 0; i < 4; ++i) {
        if (!_materias[i]) {
            _materias[i] = m->clone();
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



