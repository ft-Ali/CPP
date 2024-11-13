/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:16:05 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 14:07:12 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include "Color.hpp"
#include <iostream>
#include <string>
#include <fstream> 

std::string replace(std::string filename, std::string s1, std::string s2);
bool is_valid(std::string filename, std::string s1, std::string s2);


#endif
