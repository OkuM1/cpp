/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:35:24 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/11 19:46:55 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// Comparison Operators
bool Fixed::operator<(const Fixed &other) const {
    return this->fixedpoint_nbr < other.fixedpoint_nbr;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->fixedpoint_nbr > other.fixedpoint_nbr;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->fixedpoint_nbr >= other.fixedpoint_nbr;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->fixedpoint_nbr <= other.fixedpoint_nbr;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->fixedpoint_nbr == other.fixedpoint_nbr;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->fixedpoint_nbr != other.fixedpoint_nbr;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.fixedpoint_nbr = this->fixedpoint_nbr + other.fixedpoint_nbr;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.fixedpoint_nbr = this->fixedpoint_nbr - other.fixedpoint_nbr;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.fixedpoint_nbr = (this->fixedpoint_nbr * other.fixedpoint_nbr) >> fractional_bits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.fixedpoint_nbr = (this->fixedpoint_nbr << fractional_bits) / other.fixedpoint_nbr;
    return result;
}

// Prefix Increment
Fixed &Fixed::operator++() {
    ++fixedpoint_nbr;
    return *this;
}

// Prefix Decrement
Fixed &Fixed::operator--() {
    --fixedpoint_nbr;
    return *this;
}

// Postfix Increment
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++fixedpoint_nbr;
    return temp;
}

// Postfix Decrement
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --fixedpoint_nbr;
    return temp;
}

// Min functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

// Max functions
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

