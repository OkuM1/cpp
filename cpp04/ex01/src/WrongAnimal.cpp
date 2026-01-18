/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:21:07 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 19:21:09 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

// WrongAnimal class implementation

// Default constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

// Getter for type
std::string WrongAnimal::getType() const
{
    return type;
}

// Non-virtual makeSound method
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a generic sound!" << std::endl;
}

// WrongCat class implementation

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    type = other.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        type = other.type;
    }
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

// Destructor
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

// Non-virtual makeSound method
void WrongCat::makeSound() const
{
    std::cout << "Meow! (WrongCat)" << std::endl;
}