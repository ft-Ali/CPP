/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:36:21 by alsiavos          #+#    #+#             */
/*   Updated: 2024/12/03 11:20:11 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &src);
		Cure &operator=(const Cure &src);
		AMateria* clone() const;
		void use(ICharacter& target);
		virtual ~Cure();
};



#endif
