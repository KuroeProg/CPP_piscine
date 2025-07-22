/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 21:57:54 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/10 10:15:08 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Definition des methodes PhoneBook
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->num_contacts = 0;
	this->old_contacts = 0;
}

void	PhoneBook::add_contact()
{
	if (this->num_contacts >= 8) {
		std::cout << "Error : Too many contacts" << std::endl;
		return ;
	}
	int check = 0;

	Contact &contact = this->contacts[this->num_contacts];

	std::cout << "[ADD] Contact :" << std::endl;
	std::cout << "debug : " << this->num_contacts << std::endl;
	check = contact.fill_contact();
	contact.setIndex(this->num_contacts);
	this->old_contacts = this->num_contacts;
	if (this->num_contacts < 8 && !check)
		this->num_contacts++;
	if (this->num_contacts != 0 && this->num_contacts - 1 == this->old_contacts)
		std::cout << "\n\n !! Your contact is created !!\n\n";
}