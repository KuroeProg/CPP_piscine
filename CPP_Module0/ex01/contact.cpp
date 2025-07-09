#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact() {

}

void	Contact::setIndex(int i) {
	this->index = i + 1;
}

std::string Contact::getFirstName() const {
	return this->firstName;
}

std::string Contact::getLastName() const {
	return this->lastName;
}

std::string Contact::getNickname() const {
	return this->nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->darkestSecret;
}

int Contact::getIndex() const {
	return this->index;
}