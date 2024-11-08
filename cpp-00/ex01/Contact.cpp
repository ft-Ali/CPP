/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:52:13 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/08 14:07:14 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}
Contact::~Contact() {
}

void Contact::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}
void Contact::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}
void Contact::setNickName(const std::string &nickName) {
	this->nickName = nickName;
}
void Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
	return (firstName);
}
std::string Contact::getLastName() const {
	return (lastName);
}
std::string Contact::getNickName() const {
	return (nickName);
}
std::string Contact::getPhoneNumber() const {
	return (phoneNumber);
}
std::string Contact::getDarkestSecret() const {
	return (darkestSecret);
}
