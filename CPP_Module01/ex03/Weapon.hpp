/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:47:44 by cfiachet          #+#    #+#             */
/*   Updated: 2025/08/04 15:52:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string> 

class Weapon {
private:
	std::string type;
public :
	Weapon(const std::string &NewType) {
		this->type = NewType;
	}
	const std::string &getType() const {
		return type;
	}
	void setType(const std::string NewType) {
		this->type = NewType;
	}
	
};

#endif