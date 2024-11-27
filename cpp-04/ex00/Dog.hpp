/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:25:45 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 14:08:21 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
