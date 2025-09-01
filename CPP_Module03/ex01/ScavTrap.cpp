/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:16:04 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/01 15:16:04 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Constructor for ScavTrap called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copie) : ClapTrap(copie) {
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor for ScavTrap called for " << _name << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " cannot attack : he's dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << _name << " Has not enough energy!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing" << _attackDamage << " points of damage! "
	<< "Energy points left : " << _energyPoints << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "Guardgate for the ScavTrap " << _name << " called !" << std::endl;
}