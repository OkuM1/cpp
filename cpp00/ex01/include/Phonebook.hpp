/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:21:39 by mokutucu          #+#    #+#             */
/*   Updated: 2025/03/03 17:24:15 by mokutucu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    void addContact(const Contact &contact);
    void exitBook() const;
    void displayContacts() const;
    void displayContact(int index) const;
    std::string truncate(const std::string& str) const;

private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int currentIndex;
};

#endif