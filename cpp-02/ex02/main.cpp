/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/20 11:22:25 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5 ) / Fixed( 10 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

// int main(void) {
// 	std::cout << "========== CONSTRUCTION DES OBJETS ==========" << std::endl;

// 	Fixed a; // Default constructor
// 	std::cout << "Initial value of a: " << a << std::endl;

// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 )); // Création et multiplication
// 	std::cout << "Value of b (5.05f * 2): " << b << std::endl;

// 	std::cout << "\n========== INCREMENTATION DE a ==========" << std::endl;

// 	std::cout << "a initial: " << a << std::endl; // Affiche la valeur initiale de `a`

// 	std::cout << "Pre-increment (++a): " << ++a << std::endl; // Pré-incrémentation
// 	std::cout << "After pre-increment, a: " << a << std::endl;

// 	std::cout << "Post-increment (a++): " << a++ << std::endl; // Post-incrémentation
// 	std::cout << "After post-increment, a: " << a << std::endl;

// 	std::cout << "\n========== COMPARAISON AVEC MAX ==========" << std::endl;

//     // Utilisation de la méthode statique max
// 	std::cout << "Maximum value between a and b: " << Fixed::max(a, b) << std::endl;

// 	return 0;
// }

