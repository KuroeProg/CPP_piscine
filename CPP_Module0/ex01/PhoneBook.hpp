/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:59:43 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/06 12:28:47 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Declaration de la classe PhoneBook

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int num_contacts;

public:
	PhoneBook();
	void add_contact();
	void search_contact();
	void PhoneBook::display_index() const;
	std::string PhoneBook::format_text(std::string str);
};

#endif
// void	add_contact();
