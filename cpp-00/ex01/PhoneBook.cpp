/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:41:26 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/08 18:04:26 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {
}

bool PhoneBook::isEmpty(const std::string &str) const {
	return (str.empty());
}

std::string truncate(const std::string& str, std::size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

bool PhoneBook::isAlnum(const std::string &str) const {
	for (int i = 0; str[i]; i++)
	{
		if (!isalnum(str[i])) {
			return (false);
		}
	}
	return (true);
}

bool PhoneBook::isValidNumber(const std::string &str) const {
	for (int i = 0; str[i]; i++) {
		if (!isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::isValid(const std::string& prompt, bool numericOnly) {
	std::string input;

	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		
		if (std::cin.eof()) {
			std::cin.clear();
			break;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			break;
		}

		if (isEmpty(input)) {
			std::cout << RED + "Input is empty. Please try again." + RESET << std::endl;
			continue;
		}
		if ((numericOnly && !isValidNumber(input)) || (!numericOnly && !isAlnum(input))) {
			std::cout << RED + "Invalid input. Please try again." + RESET << std::endl;
			continue;
		}
		break;
	}
	return input;
}

void PhoneBook::addContact() {
	Contact newContact;
	std::string input;
    

	input = isValid("Enter First Name: ", false);
	if (input.empty()) 
		return;
	newContact.setFirstName(input);

	input = isValid("Enter Last Name: ", false);
	if (input.empty()) 
		return;
	newContact.setLastName(input);

	input = isValid("Enter Nickname: ", false);
	if (input.empty()) 
		return;
	newContact.setNickName(input);

	input = isValid("Enter Darkest Secret: ", false);
	if (input.empty()) 
		return;
	newContact.setDarkestSecret(input);

	input = isValid("Enter Phone Number: ", true);
	if (input.empty()) 
		return;
	newContact.setPhoneNumber(input);

	if (contactCount < 8) {
		Contacts[contactCount++] = newContact;
	} else {
		Contacts[oldestContactIndex] = newContact;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}
	std::cout << TURQ + "Contact added successfully!" + RESET << std::endl;
}

void PhoneBook::searchContacts() const {
	if (contactCount == 0) {
		std::cout << RED + "The phonebook is empty." + RESET << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Phone Number" << "|"
              << std::setw(10) << "Nickname" << std::endl;

	  for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(Contacts[i].getFirstName(), 10) << "|"
                  << std::setw(10) << truncate(Contacts[i].getLastName(), 10) << "|"
                  << std::setw(10) << truncate(Contacts[i].getPhoneNumber(), 10) << "|"
                  << std::setw(10) << truncate(Contacts[i].getNickName(), 10) << std::endl;
    }
	
	std::string input;
	int index = -1;
	while (true) {
		std::cout << "Enter index to view details: ";
		std::getline(std::cin, input);
		if(std::cin.eof())
			return ;
		bool isNumber = true;
		for (size_t i = 0; i < input.length(); i++) {		
			
			if (!isdigit(input[i])) {
				isNumber = false;
				break ;
			}
			else {
				index = input[i] - '0';
				break;
				}
		}
		if (!isNumber) {
			std::cout << RED + "Invalid input. Please enter a valid index number." + RESET << std::endl;
			continue ;
		}
		if(index >= 0  && contactCount >= index ){
			break;
			}
	}
		displayContact(index);	
}

void PhoneBook::displayContact(int index) const {
	if(!Contacts[index].getFirstName().empty()){
	std::cout << EMRD + "-------------------------------------------" + RESET << std::endl;
	std::cout << "First Name: " << Contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << Contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << Contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << Contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << Contacts[index].getDarkestSecret() << std::endl;
	std::cout << EMRD + "-------------------------------------------" + RESET << std::endl;
	}
	else
		std::cout << RED + "Invalid input. Please enter a valid index number." + RESET << std::endl;
}
