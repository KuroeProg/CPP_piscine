/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:57:00 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/22 13:15:25 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}