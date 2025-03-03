/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:49:01 by mokutucu          #+#    #+#             */
/*   Updated: 2025/03/03 17:49:07 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
    this->name = name;
    this->weapon = &weapon;
    std::cout << "HumanA constructed with name " << name << " and weapon type " << weapon.getType() << std::endl;
}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}