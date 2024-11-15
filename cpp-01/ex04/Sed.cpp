/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:15:54 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/13 17:38:29 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>
#include <fstream>

//c_str sert a "convertir" une string dans un format c_string requi par fstream
bool is_valid(std::string filename, std::string s1, std::string s2) {
	if (s1.empty()) {
		std::cerr << RED + "Error: cannot be empty." + RESET << std::endl;
		return false;
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << RED + "Error: Unable to open file " << filename << "." << RESET << std::endl;
		return false;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << RED + "Error: Unable to create file " << filename << ".replace" + RESET << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		outputFile << replace(line, s1, s2) << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return true;
}

std::string replace(std::string line, std::string s1, std::string s2) {
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos) {
		result += line.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}

	result += line.substr(pos);
	return result;
}
