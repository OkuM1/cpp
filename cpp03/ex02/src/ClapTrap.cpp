/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:51:23 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 14:48:33 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap constructed called " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this=other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->hit_points = other.hit_points;
        this->attack_damage = other.attack_damage;
        this->energy_points = other.energy_points;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

int ClapTrap::getHitPoints() 
{
    return hit_points;
}

int ClapTrap::getEnergyPoints()
{
    return energy_points;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage" << std::endl;
        energy_points--;
    }
    else if (hit_points <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
    }
    else 
    {
    std::cout << "ClapTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name  << " takes " << amount << " amount of damage" << std::endl;
    hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " regains " << amount << " hitpoints" << std::endl;
    energy_points--;
    hit_points += amount;
}