/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:25:47 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 15:00:34 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

// Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called!" << std::endl;
}

// Assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called!" << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage" << std::endl;
        energy_points--;
    }
    else if (hit_points <= 0)
    {
        std::cout << "FragTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
    }
    else 
    {
    std::cout << "FragTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
    }
}

//Unique Method

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " highfives his buddies." << std::endl;
}
