/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/18 16:28:03 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main(void) {
// 	std::cout << GRNN << "🚀 [Main] Starting program" << RESET << std::endl;

// 	Fixed a;
// 	std::cout << YLLW << "📍 [Main] Created object `a` using default constructor." << RESET << std::endl;

// 	Fixed const b(10);
// 	std::cout << YLLW << "📍 [Main] Created object `b` using int constructor with value 10." << RESET << std::endl;

// 	Fixed const c(42.42f);
// 	std::cout << YLLW << "📍 [Main] Created object `c` using float constructor with value 42.42." << RESET << std::endl;

// 	Fixed const d(b);
// 	std::cout << YLLW << "📍 [Main] Created object `d` as a copy of `b`." << RESET << std::endl;

// 	a = Fixed(1234.4321f);
// 	std::cout << YLLW << "📍 [Main] Assigned a new Fixed object to `a` with float value 1234.4321." << RESET << std::endl;

// 	std::cout << MAGN << "\n🔍 [Main] Printing values:" << RESET << std::endl;

// 	std::cout << "🖨️ a is " << a << std::endl;
// 	std::cout << "🖨️ b is " << b << std::endl;
// 	std::cout << "🖨️ c is " << c << std::endl;
// 	std::cout << "🖨️ d is " << d << std::endl;

// 	std::cout << MAGN << "\n🔍 [Main] Printing integer representations:" << RESET << std::endl;

// 	std::cout << "🔢 a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "🔢 b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "🔢 c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "🔢 d is " << d.toInt() << " as integer" << std::endl;

// 	std::cout << GRNN << "✅ [Main] Program finished successfully!" << RESET << std::endl;

// 	return 0;
// }

int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}

