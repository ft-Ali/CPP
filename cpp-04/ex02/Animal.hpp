/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:43:31 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/29 13:56:44 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Color.hpp"
# include <fstream>
# include <iostream>
# include <string>

class Animal {
	protected:
		std::string _type;
	public: 
		Animal();
		Animal(std::string type);
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};


#endif
