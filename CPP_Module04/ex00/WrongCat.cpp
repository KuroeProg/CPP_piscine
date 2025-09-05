/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:44:10 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/05 21:44:10 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat created !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copie) : WrongAnimal(copie) {
    *this = copie;
    std::cout << "WrongCat Copied !" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "WrongCat assigned by the operator" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor for WrongCat called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meooow (But Wrong)" << std::endl;
}