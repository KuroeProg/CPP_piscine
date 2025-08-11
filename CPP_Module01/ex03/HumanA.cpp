/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:31:53 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 20:31:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {

}

void    HumanA::attack() const {
	std::cout << this->name << " attack with their " << this->weapon.getType() << std::endl;
}