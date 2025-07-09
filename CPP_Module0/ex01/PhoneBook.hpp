/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:59:43 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/09 22:00:26 by cfiachet         ###   ########.fr       */
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
	void display_index() const;
	std::string format_text(std::string str) const;
	void setIndex(int i);
	void display_contact(int i) const;

};

#endif
// void	add_contact();
