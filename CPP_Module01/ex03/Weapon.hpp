/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:47:44 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/24 07:13:15 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon {
private:
	std::string type;
public :
	Weapon(const std::string &NewType) {
		type = NewType;
	}
	const std::string &getType() const {
		return type;
	}
	void setType(std::string NewType) {
		type = NewType;
	}
	
};