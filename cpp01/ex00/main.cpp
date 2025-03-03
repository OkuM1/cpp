/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:31 by mokutucu          #+#    #+#             */
/*   Updated: 2025/03/03 17:39:32 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

int main()
{
    // Stack allocation
    std::cout << "Creating zombie on stack:" << std::endl;
    randomChump("Stack Zombie");

    // Heap allocation
    std::cout << "\nCreating zombie on heap:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    // Delete heap-allocated zombie
    delete heapZombie;

    return 0;
}