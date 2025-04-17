/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:43:45 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 19:00:50 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

// Default constructor
Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

// Destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

// Getter for type
std::string Animal::getType() const
{
    return type;
}

// Default makeSound method
void Animal::makeSound() const
{
    std::cout << "Animal makes a generic sound!" << std::endl;
}
