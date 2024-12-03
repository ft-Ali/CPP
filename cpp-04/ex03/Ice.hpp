/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:28 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/03 11:21:55 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "Color.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &src);
		Ice &operator=(const Ice &src);
		AMateria* clone() const;
		void use(ICharacter& target);
		virtual ~Ice();
};

#endif

