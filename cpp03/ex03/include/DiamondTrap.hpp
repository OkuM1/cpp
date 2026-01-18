/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:21:14 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 15:17:27 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
    std::string name;

    public:
    // constructor
    DiamondTrap(std::string name);
    
    DiamondTrap(const DiamondTrap &other);
    
    DiamondTrap &operator=(const DiamondTrap &other);
    
    ~DiamondTrap();
    
    void attack(const std::string& target); // Mark from virtual in ClapTrap
    void whoAmI();
};

#endif