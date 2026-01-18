/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:34 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 15:27:12 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/DiamondTrap.hpp"

//Test
int main()
{
    ClapTrap ClapTrap("Botboy");
    ScavTrap ScavTrap("CX-101");
    FragTrap FragTrap("Hehe123");
    DiamondTrap DiamondTrap("Diamond");

    // Test attacks
    ClapTrap.attack("Goblin");
    ScavTrap.attack("Orc");
    FragTrap.attack("Elden Lord");
    DiamondTrap.attack("Dragon");

    // Test energy points
    std::cout << "ClapTrap current EP: " << ClapTrap.getEnergyPoints() << std::endl;
    std::cout << "ScavTrap current EP: " << ScavTrap.getEnergyPoints() << std::endl;
    std::cout << "FragTrap current EP: " << FragTrap.getEnergyPoints() << std::endl;
    std::cout << "DiamondTrap current EP: " << DiamondTrap.getEnergyPoints() << std::endl;

    // Test taking damage
    ClapTrap.takeDamage(5);
    ScavTrap.takeDamage(20);
    FragTrap.takeDamage(69);
    DiamondTrap.takeDamage(15);

    // Test hit points after damage
    std::cout << "ClapTrap current HP: " << ClapTrap.getHitPoints() << std::endl;
    std::cout << "ScavTrap current HP: " << ScavTrap.getHitPoints() << std::endl;
    std::cout << "FragTrap current HP: " << FragTrap.getHitPoints() << std::endl;
    std::cout << "DiamondTrap current HP: " << DiamondTrap.getHitPoints() << std::endl;

    // Test repairing
    ClapTrap.beRepaired(4);
    ScavTrap.beRepaired(10);
    FragTrap.beRepaired(1);
    DiamondTrap.beRepaired(20);

    // Test hit points after repair
    std::cout << "ClapTrap current HP: " << ClapTrap.getHitPoints() << std::endl;
    std::cout << "ScavTrap current HP: " << ScavTrap.getHitPoints() << std::endl;
    std::cout << "FragTrap current HP: " << FragTrap.getHitPoints() << std::endl;
    std::cout << "DiamondTrap current HP: " << DiamondTrap.getHitPoints() << std::endl;

    // Test unique methods
    ScavTrap.guardGate();
    FragTrap.highFivesGuys();
    DiamondTrap.whoAmI();

    return (0);
}