/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:57:11 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/22 17:42:40 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *zombie = newZombie("Arnaud");
	zombie->announce();
	delete zombie;
	randomChump("Patrick");
	randomChump("Higor");
	
	return 0;
}