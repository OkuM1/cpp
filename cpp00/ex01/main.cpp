/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:23:53 by mokutucu          #+#    #+#             */
/*   Updated: 2025/03/03 17:25:08 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Phonebook.hpp"
#include <iostream>
#include <string>

void createContact(PhoneBook& PhoneBook) {
    Contact newContact;
    std::cout << "Enter First Name: ";
    std::getline(std::cin, newContact.firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, newContact.lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, newContact.nickName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, newContact.phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, newContact.secret);
    if (!newContact.firstName.empty() && !newContact.lastName.empty() &&
        !newContact.nickName.empty() && !newContact.phoneNumber.empty() &&
        !newContact.secret.empty()) {
        PhoneBook.addContact(newContact);
        std::cout << "Contact added successfully." << std::endl;
    } else {
        std::cout << "Error: All fields must be filled." << std::endl;
    }
}

void searchContact(const PhoneBook& PhoneBook) {
    PhoneBook.displayContacts();
    std::cout << "Enter the index of the contact to display: ";
    int index;
    if (!(std::cin >> index)){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid index. Please try again." << std::endl;
        return;
    }
    std::cin.ignore(1000, '\n');
    PhoneBook.displayContact(index);
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD") {
            createContact(phoneBook);
        } else if (command == "SEARCH") {
            searchContact(phoneBook);
        } else if (command == "EXIT") {
            std::cout << "Exiting program. All contacts will be lost." << std::endl;
            phoneBook.exitBook();
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}