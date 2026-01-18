/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:58:43 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/11 19:40:58 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"
#include <iostream>

// Function to test comparison operators
void testComparisonOperators(const Fixed &a, const Fixed &b)
{
    if (a < b)
        std::cout << "a is less than b" << std::endl;
    if (a > b)
        std::cout << "a is more than b" << std::endl;
    if (a <= b)
        std::cout << "a is less than or equal to b" << std::endl;
    if (a >= b)
        std::cout << "a is greater than or equal to b" << std::endl;
    if (a == b)
        std::cout << "a is equal to b" << std::endl;
    if (a != b)
        std::cout << "a is not equal to b" << std::endl;
}

// Function to test arithmetic operators
void testArithmeticOperators()
{
    Fixed c(10);
    Fixed d(3);
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;
}

// Function to test increment and decrement operators
void testIncrementDecrementOperators(Fixed &a)
{
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl; // Prefix increment
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl; // Postfix increment
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl; // Prefix decrement
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl; // Postfix decrement
    std::cout << "a: " << a << std::endl;
}

// Function to test min and max functions
void testMinMaxFunctions() 
{
    Fixed e(42.42f);
    Fixed f(123.456f);
    std::cout << "e: " << e << ", f: " << f << std::endl;
    std::cout << "Min of e and f: " << Fixed::min(e, f) << std::endl;
    std::cout << "Max of e and f: " << Fixed::max(e, f) << std::endl;

    const Fixed g(10);
    const Fixed h(20);
    std::cout << "g: " << g << ", h: " << h << std::endl;
    std::cout << "Min of g and h (const): " << Fixed::min(g, h) << std::endl;
    std::cout << "Max of g and h (const): " << Fixed::max(g, h) << std::endl;
}

int main(void) 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    
    // Test comparison operators
    testComparisonOperators(a, b);

    // Test arithmetic operators
    testArithmeticOperators();

    // Test increment and decrement operators
    testIncrementDecrementOperators(a);

    // Test min and max functions
    testMinMaxFunctions();

    return 0;
}