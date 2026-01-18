/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:36:20 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/11 19:45:11 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int fixedpoint_nbr;
    static const int fractional_bits;

    public:
    // Default Constructor
    Fixed();

    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator
    Fixed &operator=(const Fixed &other);
    
    // Const float
    Fixed(float i);

    // Const int
    Fixed(int i);

    // Destructor
    ~Fixed();

    // Member Functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // MinMax
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);

    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    // Overload Operators as Member Functions
    bool operator<(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Prefix
    Fixed &operator++();
    Fixed &operator--();

    // Postfix
    Fixed operator++(int);
    Fixed operator--(int);
};

// Overload functions
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif