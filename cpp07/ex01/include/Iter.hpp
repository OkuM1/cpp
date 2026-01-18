/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:07:26 by mokutucu          #+#    #+#             */
/*   Updated: 2026/01/18 15:07:57 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <stdint.h>
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t len, F func) {
    for (size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

void add_one(int &n) {
    n++;
}

template <typename T>
void print_element(const T &elem) {
    std::cout << elem << " ";
}

#endif