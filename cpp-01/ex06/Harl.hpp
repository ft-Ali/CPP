/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:24:33 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 16:55:37 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include "Color.hpp"
#include <iostream>
#include <string>
#include <fstream> 

class Harl {
	private:
		void _debug();
		void _info();
		void _warning();
		void _error();

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
