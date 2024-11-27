/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:38:09 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/27 14:09:14 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
