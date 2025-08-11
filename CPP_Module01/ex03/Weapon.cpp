/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 07:08:07 by cfiachet          #+#    #+#             */
/*   Updated: 2025/08/11 20:24:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &NewType) {
	type = NewType;
}

const std::string &Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string &NewType) {
	this->type = NewType;
}