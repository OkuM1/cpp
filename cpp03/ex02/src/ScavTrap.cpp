/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:25:47 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 14:39:41 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called!" << std::endl;
}

// Assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called!" << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage" << std::endl;
        energy_points--;
    }
    else if (hit_points <= 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
    }
    else 
    {
    std::cout << "ScavTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
    }
}

// Unique method
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is guarding the Gate!!!" << std::endl;
}