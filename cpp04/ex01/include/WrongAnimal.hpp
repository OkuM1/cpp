/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:16:38 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 19:17:32 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal 
{
    protected:
        std::string type;

    public:
        WrongAnimal();                              // Default constructor
        WrongAnimal(const WrongAnimal& other);      // Copy constructor
        WrongAnimal& operator=(const WrongAnimal& other); // Copy assignment operator
        ~WrongAnimal();                             // Destructor

        std::string getType() const;                // Getter for type
        void makeSound() const;                     // Non-virtual method
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();                              // Default constructor
        WrongCat(const WrongCat& other);         // Copy constructor
        WrongCat& operator=(const WrongCat& other); // Copy assignment operator
        ~WrongCat();                             // Destructor

        void makeSound() const;                  // Non-virtual method
};

#endif