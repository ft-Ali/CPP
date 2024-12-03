/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:01:00 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/03 11:19:41 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Color.hpp"
#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria {
	protected:
	std::string _type;
	
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &src);
		AMateria &operator=(const AMateria &src);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};


#endif
