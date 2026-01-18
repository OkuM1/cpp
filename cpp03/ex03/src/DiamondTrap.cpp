/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:22:23 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 15:33:53 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap " << name << " has been created!" << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
}

// Assignment Operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap assignment operator called!" << std::endl;
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called!" << std::endl;
}

// Override attack
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

// Unique method
void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << ", and my ClapTrap name is " << ClapTrap::name << std::endl;
}