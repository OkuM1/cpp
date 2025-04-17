/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:44:55 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/16 13:38:17 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

// Default constructor
Point::Point() : x(0), y(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

// Constructor that initializes x and y with floating-point numbers
Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue)
{
    //std::cout << "Parameterized constructor called" << std::endl;
}

// Copy constructor
Point::Point(const Point &other) : x(other.x), y(other.y)
{
    //std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Point &Point::operator=(const Point &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    // x and y are constants
    (void)other;
    return *this;
}

// Destructor
Point::~Point()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }