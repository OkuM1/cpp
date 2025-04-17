/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:03:38 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/11 19:45:15 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() : fixedpoint_nbr(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixedpoint_nbr = other.fixedpoint_nbr;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixedpoint_nbr;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    fixedpoint_nbr = raw;
}

// ex01
float Fixed::toFloat(void) const
{
    return (float)fixedpoint_nbr / (1 << fractional_bits);
}

int Fixed::toInt(void) const 
{
    return fixedpoint_nbr >> fractional_bits;
}

// new Constructors
Fixed::Fixed(int i)
{
    std::cout << "Int constructor called" << std::endl;
    fixedpoint_nbr = i << fractional_bits;
}

Fixed::Fixed(float i)
{
    std::cout << "Float constructor called" << std::endl;
    fixedpoint_nbr = roundf(i * (1 << fractional_bits));
}

// Overload the << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}