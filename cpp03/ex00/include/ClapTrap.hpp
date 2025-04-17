/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:44:59 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/16 17:37:44 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap 
{
    private:
    std::string name;
    int hit_points;
    int energy_points;
    int attack_damage;

    public:
    // constructor
    ClapTrap(std::string name);
    
    ClapTrap(const ClapTrap &other);
    
    ClapTrap &operator=(const ClapTrap &other);
    
    ~ClapTrap();

    int getHitPoints();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
};

#endif