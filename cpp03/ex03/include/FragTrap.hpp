/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:21:14 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 15:12:22 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
    // constructor
    FragTrap(std::string name);
    
    FragTrap(const FragTrap &other);
    
    FragTrap &operator=(const FragTrap &other);
    
    ~FragTrap();
    
    void attack(const std::string& target); // Mark from virtual in ClapTrap
    void highFivesGuys(void);
};

#endif