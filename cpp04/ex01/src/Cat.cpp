/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:57:55 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 19:10:38 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

// Default constructor
Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other)
{
    type = other.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

// Destructor
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

// makeSound method
void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}