/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:46:42 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/03 11:46:42 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created !" << std::endl;
}

Cat::Cat(const Cat &copie) : Animal(copie) {
    brain = new Brain(*copie.brain);
    type = copie.type;
    std::cout << "Cat Copied !" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
	}
    std::cout << "Cat assigned by the operator" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Destructor for Cat called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meooow" << std::endl;
}