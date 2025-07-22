/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:57:11 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/22 13:20:27 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *a = newZombie("Foo");
	a->announce();
	delete a;
	randomChump("Patrick");
	randomChump("Higor");
	
	return 0;
}