/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:34 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 14:44:43 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

//Test
int main()
{
    ClapTrap ClapTrap("Botboy");
    ScavTrap ScavTrap("CX-101");
    
    ClapTrap.attack("Goblin");
    ScavTrap.attack("Orc");
    
    std::cout << "ClapTrap " << " current EP: " << ClapTrap.getEnergyPoints() << std::endl;
    std::cout << "ScavTrap " << " current EP: " << ScavTrap.getEnergyPoints() << std::endl;
    
    ClapTrap.takeDamage(5);
    ScavTrap.takeDamage(20);
    
    ClapTrap.beRepaired(4);
    ScavTrap.beRepaired(10);

    std::cout << "ClapTrap " << " current HP: " << ClapTrap.getHitPoints() << std::endl;
    std::cout << "ScavTrap " << " current HP: " << ScavTrap.getHitPoints() << std::endl;

    ScavTrap.guardGate();
    
    return (0);
}