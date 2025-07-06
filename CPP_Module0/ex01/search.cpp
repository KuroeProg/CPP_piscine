#include "PhoneBook.hpp"

std::string PhoneBook::format_text(std::string str)
{
	if (str.size() < 10)
	//afficher le mot dans une string + le nombre d;esoace
	if (str.size() > 9)
	//remplacer l'index 9 par un . et copier le debut du mots
	return (string);

}

void PhoneBook::display_index() const
{
	std::cout << "     index|first name| last name|  nickname|" << std::endl;

	for (int i = 0; i < this->num_contacts; ++i)
	{
		std::cout << "         " << i << "|"
		          << format_text(this->contacts[i].getFirstName()) << "|"
		          << format_text(this->contacts[i].getLastName()) << "|"
		          << format_text(this->contacts[i].getNickname()) << "|"
		          << std::endl;
	}
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