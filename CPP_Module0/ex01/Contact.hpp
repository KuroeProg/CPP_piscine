//Declaration de la classe Contact
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	int index;

public:
	Contact();
	static void add_contact();
	static void	search_contact();
	//other functions
};


#endif