/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:41:26 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/06 15:34:13 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() : contact_count(0), oldest_contact_index(0) {
}

bool PhoneBook::is_empty(const std::string& str) const {
    return str.empty();
}

bool PhoneBook::is_alnum(const std::string& str) const {
    for (int i = 0; str[i]; i++) {
        if (!isalnum(str[i])) {
            return false;
        }
    }
    return true;
}

bool PhoneBook::is_valid_number(const std::string& str) const {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add_contact() {
	Contact	new_contact;
	std::string input;
	
	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	if(is_empty(input) || !is_alnum(input)) {
		std::cout << "First Name is empty." << std::endl;
		return ;
	}
	new_contact.set_first_name(input);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	if(is_empty(input) || !is_alnum(input)) {
		std::cout << "Last Name is empty." << std::endl;
		return ;
	}
	new_contact.set_last_name(input);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	if(is_empty(input) || !is_alnum(input)) {
		std::cout << "Nickname is empty." << std::endl;
		return ;
	}
	new_contact.set_nickname(input);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	if(is_empty(input) || !is_valid_number(input)) {
		std::cout << "Phone Number is empty or no-digits." << std::endl;
		return ;
	}
	new_contact.set_phone_number(input);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	if(is_empty(input) || !is_alnum(input)) {
		std::cout << "Darkest Secret is empty." << std::endl;
		return ;
	}
	new_contact.set_darkest_secret(input);
	if (contact_count < 8) {
		contacts[contact_count++] = new_contact;
	}
	else {
		contacts[oldest_contact_index] = new_contact;
		oldest_contact_index = (oldest_contact_index + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}


void PhoneBook::search_contacts() const {
	if (contact_count == 0) {
		std::cout << "The phonebook is empty." << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Phone Number" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contact_count; ++i) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].get_first_name().substr(0,9) << "|";
		std::cout << std::setw(10) << contacts[i].get_last_name().substr(0,9) << "|";
		std::cout << std::setw(10) << contacts[i].get_phone_number().substr(0,9) << "|";
		std::cout << std::setw(10) << contacts[i].get_nickname().substr(0,9) << std::endl;
	}

	std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);
    // int index;

	if (input.empty()) {
        std::cout << "No input provided." << std::endl;
        return;
    }
	
		
	}
  


void PhoneBook::display_contact(int index) const {
	const Contact &contact = contacts[index];
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}
