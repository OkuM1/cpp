/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:58:43 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/11 13:03:15 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"
#include <iostream>

#include <iostream>
int main( void ) 
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    
    c = b;
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}