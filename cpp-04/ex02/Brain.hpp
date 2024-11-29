/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:43:24 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/28 10:22:22 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain {
	protected:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
		
		~Brain();
		
};


#endif
