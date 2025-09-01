/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:16:45 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/01 09:16:45 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
}

ClapTrap::ClapTrap(const ClapTrap &copie)
	:   _name(copie._name),
		_hitPoints(copie._hitPoints),
		_energyPoints(copie._energyPoints),
		_attackDamage(copie._attackDamage) {
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other) {
		_name			= other._name;
		_hitPoints		= other._hitPoints;
		_energyPoints	= other._energyPoints;
		_attackDamage	= other._attackDamage;
	}
	
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " is destroyed" << std::endl;
}

/* getters */
const std::string	&ClapTrap::getName() const {
	return _name;
}

int					ClapTrap::getHitPoints() const {
	return _hitPoints;
}

int					ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

int					ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void	ClapTrap::attack(const std::string &target) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot attack : he's dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " Has not enough energy!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! "
	<< "Energy points left : " << _energyPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	_hitPoints -= (int)amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! "
	<< "Health points left : " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead; he cannot resurrect!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " Repaired himself by " << amount << " of HP!"
	<< " Current HP : " << _hitPoints << std::endl;
}