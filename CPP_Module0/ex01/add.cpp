#include "PhoneBook.hpp"

Contact::Contact() {

}

int		check_number(const std::string &str) {
	if (str.empty())
		return 0;
	if (str.size() > 16) {
		std::cout << "The number is too long" << std::endl;
		return 0;
	}
	for (size_t i = 0; i < str.size(); i++) {
		if (!(std::isdigit(str[i])))
			return 0;
	}
	return 1;
}

void	Contact::add_contact()
{
	Contact contact;

	std::cout << "[ADD] Contact :" << std::endl;
	if (num_contacts > 7) {
		std::cout << "Error : Too many contacts" << std::endl;
		return ;
	}
	std::cout << "Enter first name" << std::endl;
	std::cin >> contact.firstName;
	std::cout << "Enter last name" << std::endl;
	std::cin >> contact.lastName;
	std::cout << "Enter nickname" << std::endl;
	std::cin >> contact.nickname;
	std::cout << "Enter number" << std::endl;
	std::cin >> contact.phoneNumber;
	if (!check_number(contact.phoneNumber))
		return ;
	std::cout << "Enter darkest secret" << std::endl;
	std::cin >> contact.darkestSecret;
	std::cout << "\n\n !! Your contact is created !!\n\n";
	contact.index++ && num_contacts++;
	std::cout << contact.index << num_contacts;
}