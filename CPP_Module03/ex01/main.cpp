/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:16:50 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/01 09:16:50 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main() {
	std::cout << "ClapTrap Tests :" << std::endl;
	ClapTrap a("a");
	ClapTrap b("b");

	a.attack("a zombie");
	b.attack("a human i guess");
	a.takeDamage(3);
	b.takeDamage(5);
	a.beRepaired(2);
	b.beRepaired(4);
	for (int i = 0; i < 11; i++)
		a.attack("Napstablook");
	b.takeDamage(20);
	b.attack("cible");
	b.beRepaired(5);

	std::cout << "ScavTrap Tests : " << std::endl;
	{
		ScavTrap guardian("Guardian"); 
	}
	ScavTrap warrior("Kris");
	warrior.attack("enemy");
	warrior.takeDamage(30);
	warrior.beRepaired(10);
	ScavTrap sentinel("Watcher");
	sentinel.guardGate();

	return 0;

}
