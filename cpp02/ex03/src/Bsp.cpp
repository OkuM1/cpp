/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:31:07 by mokutucu          #+#    #+#             */
/*   Updated: 2025/04/16 13:37:12 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static Fixed cross(Point const &a, Point const &b, Point const &p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

static bool isPointOnEdge(Fixed crossProduct) {
    return crossProduct == 0;
}

static bool haveSameSign(Fixed cross1, Fixed cross2, Fixed cross3) {
    return (cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = cross(a, b, point);
    Fixed cross2 = cross(b, c, point);
    Fixed cross3 = cross(c, a, point);

    // Check if the point lies on any of the triangle's edges
    if (isPointOnEdge(cross1) || isPointOnEdge(cross2) || isPointOnEdge(cross3))
        return false; // Change to true if edge points should be considered inside

    // Check if all cross products have the same sign
    return haveSameSign(cross1, cross2, cross3);
}