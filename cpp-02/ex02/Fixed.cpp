/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:47:24 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/18 17:47:03 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor (initializes _value to 0)
Fixed::Fixed() : _value(0) {
	std::cout << GRNN << "✅ [Default Constructor] Object created with _value = 0" << RESET << std::endl;
}

// Copy constructor (creates a new Fixed object as a copy of another)
Fixed::Fixed(const Fixed &src) {
	std::cout << YLLW << "🔄 [Copy Constructor] Copying object with _value = " << src.getRawBits() << RESET << std::endl;
	*this = src; // Uses the assignment operator to copy the data
}

// Constructor with an integer value, point of the function is to convert an integer number to a fixed-point number
// exemple de fixed-point : 42.75 (float) = 42 + 0.75 puis 42 = 42 * 256 = 10752 + 0.75 * 256 = 192 (car 0.75 * 256 = 192) = 10944
// pourquoi 256 pcq 8 bits (2^8 = 256)
Fixed::Fixed(int const &value) {
	std::cout << CYAN << "🔢 [Int Constructor] Initializing with integer value: " << value << RESET << std::endl;
	this->_value = value << this->_bits; // Converts the integer to fixed-point by shifting left
}

// Constructor with a floating-point value, point of the function is to convert a floating-point number to a fixed-point number
Fixed::Fixed(float const &value) {
	std::cout << CYAN << "🔢 [Float Constructor] Initializing with float value: " << value << RESET << std::endl;
	this->_value = roundf(value * (1 << this->_bits)); // Converts float to fixed-point using rounding
}

// Destructor
Fixed::~Fixed() {
	std::cout << RED << "💥 [Destructor] Cleaning up object with _value = " << this->_value << RESET << std::endl;
}

// Getter function (returns the raw value of _value)
int Fixed::getRawBits(void) const {
	std::cout << BLUE << "🔍 [getRawBits] Returning raw value: " << this->_value << RESET << std::endl;
	return (this->_value);
}

// Setter function (sets the raw value of _value)
void Fixed::setRawBits(int const raw) {
	std::cout << BLUE << "✏️ [setRawBits] Setting raw value to: " << raw << RESET << std::endl;
	this->_value = raw;
}

// Converts the fixed-point value to a floating-point number
// exemple de toFloat fait la conversion de 42 en 42.0
float Fixed::toFloat(void) const {
	std::cout << GRNN << "🔍 [toFloat] Converting _value = " << this->_value << " to float" << RESET << std::endl;
	return ((float)this->_value / (1 << this->_bits)); // Converts by shifting right (scaling down) to nearest integer
}

// Converts the fixed-point value to an integer
// exemple de toInt fait la conversion de 42.75 en 42
int Fixed::toInt(void) const {
	std::cout << GRNN << "🔍 [toInt] Converting _value = " << this->_value << " to int" << RESET << std::endl;
	return (this->_value >> this->_bits); // Converts by shifting right (scaling down)
}

// Assignation operator overload (assigns the value of one Fixed object to another)
// Overload operator c'est pour faire une copie de l'objet source dans l'objet destination
Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << PURP << "🔄 [Assignment Operator] Assigning _value = " << rhs.getRawBits() << RESET << std::endl;
	if (this != &rhs) // Prevent self-assignment
		this->_value = rhs.getRawBits(); // Copies the raw value from the source object
	return (*this);
}

// Overload of the << operator (outputs the floating-point representation of the fixed-point value)
// exemple de operator << fait la copie de l'objet source dans l'objet destination
std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat(); // Outputs the float value of the Fixed object
	std::cout << CYAN << "🖨️ [Operator<<] Outputting float value: " << rhs.toFloat() << RESET << std::endl;
	return (o);
}
// ostream is a class that represents an output stream, and the << operator is an operator that takes an output stream and a value to output, and returns the output stream.

/*********** Comparaison ***********/

bool Fixed::operator>(const Fixed &rhs) const {
    return this->_value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return this->_value <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
	return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return this->_value != rhs.getRawBits();
}
 /*********** OPERATEUR ARITHMETIQUE ***********/

Fixed Fixed::operator+(Fixed const &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

/*********** OPERATEUR D'INCREMENTATION ET DE DECREMENTATION ***********/

Fixed &Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

/*********** FONCTIONS STATIQUES MIN/MAX ***********/

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b); // Si A est plus petit que B alors on retourne A sinon on retourne B
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b); // Si A est plus grand que B alors on retourne A sinon on retourne B
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b); // Si A est plus petit que B alors on retourne A sinon on retourne B
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b); // Si A est plus grand que B alors on retourne A sinon on retourne B
}
