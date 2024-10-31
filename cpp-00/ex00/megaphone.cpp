/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:34:15 by alsiavos          #+#    #+#             */
/*   Updated: 2024/10/31 17:41:35 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

int	main(int c, char **v)
{
	if (c == 1)
	{
		std::cout << RED << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << RESET << std::endl;
		return (0);
	}
	else
	{
		for(int i = 1; i < c; i++)
		{
			for (int j = 0; v[i][j]; j++)
				std::cout << BLUE << (char)toupper(v[i][j]) << RESET;
		}
	}
	std::cout << std::endl;
	return (0);
}