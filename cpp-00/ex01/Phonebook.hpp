/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:08:35 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/08 12:00:28 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream> 
#include "color.hpp"
#include "Contact.hpp"
#include <cctype>
#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int contact_count;
    int oldest_contact_index;
	bool is_empty(const std::string& str) const;
	bool is_valid_number(const std::string& str) const;
	bool is_alnum(const std::string& str) const;
    std::string isValid(const std::string& prompt, bool numericOnly);

public:
    PhoneBook();
	~PhoneBook();
    void add_contact();
    void search_contacts() const;
    void display_contact(int index) const;
};


#endif
