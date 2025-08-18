/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:37:18 by cfiachet          #+#    #+#             */
/*   Updated: 2025/08/18 12:37:21 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int		main( void ) {
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

/*
int main() {
    Fixed a;                // constructeur par défaut
    std::cout << "a: " << a.getRawBits() << std::endl;

    a.setRawBits(10);       // on modifie _nbr
    std::cout << "a après setRawBits(10): " << a.getRawBits() << std::endl;

    Fixed b(a);             // constructeur de copie
    std::cout << "b (copie de a): " << b.getRawBits() << std::endl;

    Fixed c;
    c = b;                  // opérateur d'affectation
    std::cout << "c (après c = b): " << c.getRawBits() << std::endl;

    a.setRawBits(20);       // on modifie a encore
    std::cout << "a après setRawBits(20): " << a.getRawBits() << std::endl;
    std::cout << "b reste inchangé: " << b.getRawBits() << std::endl;
    std::cout << "c reste inchangé: " << c.getRawBits() << std::endl;

    return 0;
}*/
