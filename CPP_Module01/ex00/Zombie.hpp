/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:57:07 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/22 13:08:41 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
		std::string _name;
public:

		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif