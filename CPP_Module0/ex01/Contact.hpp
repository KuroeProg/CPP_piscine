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
	void fill_contact();
	void setIndex(int i);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
	// std::string getFirstName() const{
	// 	return this->firstName;
	// }
	// std::string getLastName() const{
	// 	return this->lastName;
	// }
	// std::string getNickname() const{
	// 	return this->nickname;
	// }
	int getIndex() const;
	//other functions
};


#endif