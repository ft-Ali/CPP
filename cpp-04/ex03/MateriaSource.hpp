/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:54:47 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/03 11:22:19 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _materias[4];
		int _materiasCount;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);
		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};



#endif
