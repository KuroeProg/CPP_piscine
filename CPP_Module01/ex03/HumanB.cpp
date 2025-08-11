/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:27:36 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 20:27:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name) {
    this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack() const {
    if (this->weapon == NULL)
        std::cout << this->name << " does not have weapon." << std::endl;
    else
        std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}