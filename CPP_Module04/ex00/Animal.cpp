/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:28:41 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/03 11:28:41 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Constructor \"Animal\" created [default]" << std::endl; 
}

Animal::Animal(const Animal &copie) : type(copie.type) {
	std::cout << "Animal [default], copied !" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal [default] assigned by operator" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal [default] destroyed" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Some general or [default] sound" << std::endl;
}