/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:36:37 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/16 13:36:36 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
    Fixed x;
    Fixed y;

    public:
    // Default
    Point();

    // Param Constructor
    Point(const float x, const float y);

    // Copy const
    Point(const Point &other);

    // Copy assignment overload
    Point &operator=(const Point &other);

    // Destructor
    ~Point();

    //getters
    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif