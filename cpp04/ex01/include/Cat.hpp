/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:44:59 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 19:10:22 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    // constructor
    Cat();
    
    Cat(const Cat &other);
    
    Cat &operator=(const Cat &other);
    
    ~Cat();

    void makeSound() const;
};

#endif