/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:47:17 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/22 23:33:18 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	announce() {
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

int	main(void)
{
	Zombie *horde;
	int		num = 5;
	int 	i = 0;

	if (num == 0)
		return (0);
	horde = zombieHorde(num, "Horde");
	while (i < num)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;

	return (0);
	
}