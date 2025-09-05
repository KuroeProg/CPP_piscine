#include "PhoneBook.hpp"

void	PhoneBook::display_contact(int i) const
{
	const Contact &c = contacts[i];

	std::cout << "First Name : " << c.getFirstName() << std::endl;
	std::cout << "Last Name : " << c.getLastName() << std::endl;
	std::cout << "Nickname : " << c.getNickname() << std::endl;
	std::cout << "Phone Number : " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << c.getDarkestSecret() << std::endl;
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

	int option = 0;

	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < this->num_contacts ; ++i)
	{
		std::cout << "         " << i << "|"
		          << format_text(this->contacts[i].getFirstName()) << "|"
		          << format_text(this->contacts[i].getLastName()) << "|"
		          << format_text(this->contacts[i].getNickname()) << "|"
		          << std::endl;
	}
	std::cout << "Choose an index [0...7]" << std::endl;
	std::cin >> option;
	while (!(option >= 0 && option < 8)) {
		std::cout << "Error : not a good index value" << std::endl;
		break ;
	}
	if (option <= this->num_contacts)
		display_contact(option);
	else
		std::cout << "This index does not exist" << std::endl;
}


void	PhoneBook::search_contact()
{
	std::cout << "[SEARCH] Contact : please insert an index" << std::endl;
	if (this->num_contacts == 0) {
		std::cout << "No contact to display" << std::endl;
		return ;
	}
	display_index();
}