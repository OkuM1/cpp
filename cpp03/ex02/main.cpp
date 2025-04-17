/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:34 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 15:02:43 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

//Test
int main()
{
    ClapTrap ClapTrap("Botboy");
    ScavTrap ScavTrap("CX-101");
    FragTrap FragTrap("Hehe123");
    
    ClapTrap.attack("Goblin");
    ScavTrap.attack("Orc");
    FragTrap.attack("Elden Lord");
    
    std::cout << "ClapTrap " << " current EP: " << ClapTrap.getEnergyPoints() << std::endl;
    std::cout << "ScavTrap " << " current EP: " << ScavTrap.getEnergyPoints() << std::endl;
    std::cout << "FragTrap " << " current EP: " << FragTrap.getEnergyPoints() << std::endl;
    
    ClapTrap.takeDamage(5);
    ScavTrap.takeDamage(20);
    FragTrap.takeDamage(69);
    
    std::cout << "ClapTrap " << " current HP: " << ClapTrap.getHitPoints() << std::endl;
    std::cout << "ScavTrap " << " current HP: " << ScavTrap.getHitPoints() << std::endl;
    std::cout << "FragTrap " << " current HP: " << FragTrap.getHitPoints() << std::endl;

    ClapTrap.beRepaired(4);
    ScavTrap.beRepaired(10);
    FragTrap.beRepaired(1);

    std::cout << "ClapTrap " << " current HP: " << ClapTrap.getHitPoints() << std::endl;
    std::cout << "ScavTrap " << " current HP: " << ScavTrap.getHitPoints() << std::endl;
    std::cout << "FragTrap " << " current HP: " << FragTrap.getHitPoints() << std::endl;

    ScavTrap.guardGate();
    FragTrap.highFivesGuys();
    
    return (0);
}