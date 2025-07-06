/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:25:08 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/06 09:01:57 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// boucle principale + instance Phonebook
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>


int	main(void)
{

	std::string option;
	PhoneBook phonebook;

	std::cout << "A W E S O M E   P H O N E   B O O K" << std::endl;
	std::cout << "Welcome to the Awesome Phone Book !\n\n" << std::endl;
	while (1)
	{
		std::cout << "\nPlease, Enter an option : 'ADD/SEARCH/EXIT'" << std::endl;
		std::cin >> option;
		if (option == "ADD") {
			phonebook.add_contact();
		}
		else if(option == "SEARCH") { //verifier s'il y a deja un contact d'entree
			phonebook.search_contact();
		}
		else if (option == "EXIT") {
			exit(0);
		}
		else
			std::cout << "Please, Select a valid option" << std::endl;
	}
	return (0);
}