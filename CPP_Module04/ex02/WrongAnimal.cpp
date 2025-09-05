/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:32:27 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/05 21:32:27 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "Constructor for \"WrongAnimal\" called !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copie) : type(copie.type) {
	std::cout << "Copy constructor for \"WrongAnimal\" called !" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		this->type = other.type;
	std::cout << "Operator for \"WrongAnimal\" called !" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor for \"WrongAnimal\" called !" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Some general default sound of Animal" << std::endl;
}
