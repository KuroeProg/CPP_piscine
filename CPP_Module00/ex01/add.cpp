#include "PhoneBook.hpp"

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

int	Contact::fill_contact()
{
	std::string input;

	std::cout << "Enter first name" << std::endl;
	std::cin >> input;
	this->firstName = input;

	std::cout << "Enter last name" << std::endl;
	std::cin >> input;
	this->lastName = input;

	std::cout << "Enter nickname" << std::endl;
	std::cin >> input;
	this->nickname = input;

	std::cout << "Enter number" << std::endl;
	std::cin >> input;
	if (!check_number(input))
		return 1;
	this->phoneNumber = input;
	
	std::cout << "Enter darkest secret" << std::endl;
	std::cin >> input;
	this->darkestSecret = input;

	return 0;
}