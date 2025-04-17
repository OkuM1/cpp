/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:34 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 14:17:28 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

//Test
int main()
{
    ClapTrap ClapTrap("Bob");

    ClapTrap.attack("enemy");
    ClapTrap.takeDamage(5);
    ClapTrap.beRepaired(4);

    std::cout << "ClapTrap " << "Bob's current HP: " << ClapTrap.getHitPoints() << std::endl;
    
    return (0);
}