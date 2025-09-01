/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:25:01 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/01 19:25:01 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &copie);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();

    void attack(const std::string &target); 
    void highFivesGuys(void);
};

#endif
