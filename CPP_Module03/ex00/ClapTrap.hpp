/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:16:48 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/01 09:16:48 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	private:
		std::string _name;
		int         _hitPoints;
		int         _energyPoints;
		int         _attackDamage;
	
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copie);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
	
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const std::string	&getName() const;
		int					getHitPoints() const;
		int					getEnergyPoints() const;
		int					getAttackDamage() const;
};


#endif