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
    std::cout << "Cat created !" << std::endl;
}

Cat::Cat(const Cat &copie) : Animal(copie) {
    *this = copie;
    std::cout << "Cat Copied !" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "Cat assigned by the operator" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor for Cat called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meooow" << std::endl;
}