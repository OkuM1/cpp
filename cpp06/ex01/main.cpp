/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:58:22 by mokutucu          #+#    #+#             */
/*   Updated: 2026/01/18 14:59:00 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"

//The idea of serialization is to convert a data structure into a format that can be easily stored and reconstructed later.

int main() {
    // Example usage
    Data data;
    data.value = 42;

    // Serialize the pointer
    uintptr_t serializedData = Serializer::serialize(&data);
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Serialized Data address: " << serializedData << std::endl;

    // Deserialize the pointer
    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Return value: " << deserializedData << std::endl;
    std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;

    return 0;
}