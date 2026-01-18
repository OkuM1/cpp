/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:21:14 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 15:12:35 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
    // constructor
    ScavTrap(std::string name);
    
    ScavTrap(const ScavTrap &other);
    
    ScavTrap &operator=(const ScavTrap &other);
    
    ~ScavTrap();
    
    void attack(const std::string& target); // Mark from virtual in ClapTrap
    void guardGate();
};

#endif