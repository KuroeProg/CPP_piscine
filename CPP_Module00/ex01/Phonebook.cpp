/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 21:57:54 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/07 15:49:32 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->num_contacts = 0;
	this->old_contacts = 0;
}

void	PhoneBook::add_contact()
{
	int index;

	if (this->num_contacts < 8)
		index = this->num_contacts;
	else
		index = this->old_contacts;		
	int check = 0;

	Contact &contact = this->contacts[index];

	std::cout << "[ADD] Contact :" << std::endl;
	check = contact.fill_contact();
	contact.setIndex(index);
	
	if (!check) {
		if (this->num_contacts < 8)
			this->num_contacts++;
		else
			this->old_contacts = (this->old_contacts + 1) % 8;

		std::cout << "\n\n !! Your contact is created !!\n\n";
	}
}