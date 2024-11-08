/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:41:26 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/08 12:09:02 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() : contact_count(0), oldest_contact_index(0) {
}

bool PhoneBook::is_empty(const std::string &str) const {
	return (str.empty());
}

bool PhoneBook::is_alnum(const std::string &str) const {
	for (int i = 0; str[i]; i++)
	{
		if (!isalnum(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool PhoneBook::is_valid_number(const std::string &str) const {
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
		if(std::cin.eof())
			break;
        if (is_empty(input) ) {
            std::cout << RED + "Input is empty. Please try again." + RESET << std::endl;
            continue;
        }
        if ((numericOnly && !is_valid_number(input)) || (!numericOnly && !is_alnum(input))) {
            std::cout << RED + "Invalid input. Please try again." + RESET << std::endl;
            continue;
        }
        break;
    }

    return input;
}

void PhoneBook::add_contact() {
    Contact new_contact;

    // Saisie et validation pour chaque champ
    new_contact.set_first_name(isValid("Enter First Name: ", false));
    if(!new_contact.get_first_name().empty()){
	new_contact.set_last_name(isValid("Enter Last Name: ", false));
    new_contact.set_nickname(isValid("Enter Nickname: ", false));
    new_contact.set_darkest_secret(isValid("Enter Darkest Secret: ", false));
    new_contact.set_phone_number(isValid("Enter Phone Number: ", true));}

    // Ajout du contact au phonebook
    if (contact_count < 8) {
        contacts[contact_count++] = new_contact;
    } else {
        contacts[oldest_contact_index] = new_contact;
        oldest_contact_index = (oldest_contact_index + 1) % 8;
    }
	if(!new_contact.get_first_name().empty())
    	std::cout << TURQ + "Contact added successfully!" + RESET << std::endl;
}	

void PhoneBook::search_contacts() const {
	if (contact_count == 0) {
		std::cout << RED + "The phonebook is empty." + RESET << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Phone Number" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contact_count; ++i) {
		std::cout << std::setw(10) << i << ".";
		std::cout << std::setw(10) << contacts[i].get_first_name().substr(0,9) << ".";
		std::cout << std::setw(10) << contacts[i].get_last_name().substr(0,9) << ".";
		std::cout << std::setw(10) << contacts[i].get_phone_number().substr(0,9) << ".";
		std::cout << std::setw(10) << contacts[i].get_nickname().substr(0,9) << std::endl;
	}

	std::cout << "Enter index to view details: ";
	std::string input;
	int index = -1;
	while (true) {
		std::cout << "Enter index to view details: ";
		std::getline(std::cin, input);

		bool is_number = true;
		for (size_t i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				is_number = false;
				break ;
			}
		}

		if (!is_number) {
			std::cout << RED + "Invalid input. Please enter a valid index number." + RESET << std::endl;
			continue ;
		}

		index = 0;
		for (size_t i = 0; i < input.length(); i++) {
			index = index * 10 + (input[i] - '0');
		}

		if (index < 0 || index >= contact_count) {			
			std::cout << RED + "Invalid input. Please enter a valid index number." + RESET << std::endl;
		}
		else {
			break ;
		}
	}

	display_contact(index);
}

void PhoneBook::display_contact(int index) const {
	const Contact &contact = contacts[index];
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}
