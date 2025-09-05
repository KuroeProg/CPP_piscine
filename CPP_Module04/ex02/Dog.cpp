/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:41:29 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/03 11:41:29 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog created !" << std::endl;
}

Dog::Dog(const Dog &copie) : Animal(copie) {
	brain = new Brain(*copie.brain);
	type = copie.type;
	std::cout << "Dog Copied !" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
	}
	std::cout << "Dog assigned by the operator" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Destructor for Dog called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}