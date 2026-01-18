/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Find.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:11:59 by mokutucu          #+#    #+#             */
/*   Updated: 2026/01/18 15:11:59 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_HPP
#define FIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iterator>

template <typename T>
int easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container.");
    return std::distance(container.begin(), it);
}

#endif