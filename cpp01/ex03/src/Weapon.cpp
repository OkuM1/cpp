/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:49:36 by mokutucu          #+#    #+#             */
/*   Updated: 2025/03/03 17:49:45 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
}

const std::string &Weapon::getType() {
    return type;
}

void Weapon::setType(std::string weapon_name) {
    type = weapon_name;
}