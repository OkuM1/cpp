/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:58:43 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/16 13:35:50 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"
#include "include/Fixed.hpp"

void testBsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
    std::cout << "Testing point (" << point.getX() << ", " << point.getY() << "): ";
    if (bsp(a, b, c, point))
        std::cout << "Inside the triangle" << std::endl;
    else
        std::cout << "Outside the triangle" << std::endl;
}

int main()
{
    // Define the vertices of the triangle
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    std::cout << "Triangle vertices: A(0, 0), B(10, 0), C(0, 10)" << std::endl;

    // Test points
    Point insidePoint(2, 2);  // Inside the triangle
    Point edgePoint(0, 5);    // On the edge of the triangle
    Point vertexPoint(0, 0);  // On a vertex of the triangle
    Point outsidePoint(15, 15); // Outside the triangle

    // Run tests
    testBsp(a, b, c, insidePoint);
    testBsp(a, b, c, edgePoint);
    testBsp(a, b, c, vertexPoint);
    testBsp(a, b, c, outsidePoint);

    return 0;
}