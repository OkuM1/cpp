/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:32 by mokutucu          #+#    #+#             */
/*   Updated: 2025/03/03 17:42:19 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);

    private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
