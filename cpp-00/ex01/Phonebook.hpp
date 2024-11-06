/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:08:35 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/06 15:23:25 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <iostream>
#include <cstring>
#include <iomanip>
#include "color.hpp"
#include "Contact.hpp"
#include <cctype>

class PhoneBook {
private:
    Contact contacts[8];
    int contact_count;
    int oldest_contact_index;
	bool is_empty(const std::string& str) const;
	bool is_valid_number(const std::string& str) const;
	bool is_alnum(const std::string& str) const;

public:
    PhoneBook();
	~PhoneBook();
    void add_contact();
    void search_contacts() const;
    void display_contact(int index) const;
};


#endif
