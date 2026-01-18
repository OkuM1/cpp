/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:34 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/17 19:20:55 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Outputs: Meow!
    j->makeSound(); // Outputs: Woof! Woof!
    meta->makeSound(); // Outputs: Animal makes a generic sound!

    delete meta;
    delete j;
    delete i;

    std::cout << "------------------------" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound(); // Outputs: WrongAnimal makes a generic sound!
    wrongMeta->makeSound(); // Outputs: WrongAnimal makes a generic sound!

    delete wrongMeta;
    delete wrongCat;

    return 0;
}