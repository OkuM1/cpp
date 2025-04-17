/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:36:20 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/11 19:44:42 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
    
    // Destructor
    ~Fixed();

    // Member Functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif