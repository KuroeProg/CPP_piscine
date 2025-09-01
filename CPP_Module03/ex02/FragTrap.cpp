/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 00:52:20 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/02 00:52:20 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Constructor for FragTrap " << _name << " called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copie) : ClapTrap(copie) {
    std::cout << "Copy constructor for FragTrap " << _name << " called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "Assignment operator for FragTrap " << _name << " called!" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " is destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (_hitPoints <= 0) {
		std::cout << "FragTrap " << _name << " cannot attack : he's dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "FragTrap " << _name << " Has not enough energy!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! "
	<< "Energy points left : " << _energyPoints << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << "The high five was a thing before" << std::endl;
}
