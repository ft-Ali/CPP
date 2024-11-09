/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:08:35 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/08 18:02:54 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream> 
#include "Color.hpp"
#include "Contact.hpp"
#include <cctype>
#include <string>

class PhoneBook {
private:
	Contact Contacts[8];
	int contactCount;
	int oldestContactIndex;
	bool isEmpty(const std::string& str) const;
	bool isValidNumber(const std::string& str) const;
	bool isAlnum(const std::string& str) const;
	std::string isValid(const std::string& prompt, bool numericOnly);

public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContacts() const;
	void displayContact(int index) const;
};


#endif
