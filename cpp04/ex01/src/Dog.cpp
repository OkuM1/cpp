/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:57:55 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 19:10:33 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

// Default constructor
Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
    type = other.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

// Destructor
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

// makeSound method
void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}