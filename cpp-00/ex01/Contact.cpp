/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:52:13 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/06 11:36:39 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}
Contact::~Contact() {
}

void Contact::set_first_name(const std::string &first_name)
{
	this->first_name = first_name;
}
void Contact::set_last_name(const std::string &last_name)
{
	this->last_name = last_name;
}
void Contact::set_nickname(const std::string &nickname)
{
	this->nickname = nickname;
}
void Contact::set_phone_number(const std::string &phone_number)
{
	this->phone_number = phone_number;
}
void Contact::set_darkest_secret(const std::string &darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string Contact::get_first_name() const
{
	return (first_name);
}
std::string Contact::get_last_name() const
{
	return (last_name);
}
std::string Contact::get_nickname() const
{
	return (nickname);
}
std::string Contact::get_phone_number() const
{
	return (phone_number);
}
std::string Contact::get_darkest_secret() const
{
	return (darkest_secret);
}
