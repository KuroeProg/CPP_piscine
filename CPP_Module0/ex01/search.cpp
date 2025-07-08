#include "PhoneBook.hpp"

void	PhoneBook::display_contact()
{
	
}

std::string PhoneBook::format_text(std::string str) const
{
	if (str.size() < 10) {
		return std::string(10 - str.size(), ' ') + str;
	}
	else if (str.size() > 10) {
		return (str.substr(0, 9) + ".");
	}
	return str;
}

void PhoneBook::display_index() const
{

	int option;

	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < this->num_contacts; ++i)
	{
		std::cout << "         " << i << "|"
		          << format_text(this->contacts[i].getFirstName()) << "|"
		          << format_text(this->contacts[i].getLastName()) << "|"
		          << format_text(this->contacts[i].getNickname()) << "|"
		          << std::endl;
	}
	std::cout << "Choose an index [1/8]" << std::endl;
	while (!(option > 0 && option < 9)) {
		std::cout << "Error : not a good index value" << std::endl;
	}
	display_contact(this->contact[option]);
	//demander l'index a selectionner (prendre l'index dans le nombres de this->contact[i])
	//une fois l'index choisi, envoye la valeur choisi dans une fonction et l'afficher dans un display contact ?
}


void	PhoneBook::search_contact()
{
	std::cout << "[SEARCH] Contact : please insert an index" << std::endl;
	if (this->num_contacts == 0) {
		std::cout << "No Contact to display" << std::endl;
		return ;
	}
	display_index();
}