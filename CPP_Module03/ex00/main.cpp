/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:16:50 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/01 09:16:50 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap a("a");
    ClapTrap b("b");

    ClapTrap c(a);
    ClapTrap d("d");
    d = b;

    a.attack("un arbre");
    b.attack("un caillou");
    a.takeDamage(3);
    b.takeDamage(5);
    a.beRepaired(2);
    b.beRepaired(4);

    for (int i = 0; i < 12; i++) {
        a.attack("x target");
    }

    b.takeDamage(20); 
    b.attack("target"); 
    b.beRepaired(5);   

    ClapTrap e("e");
    e.takeDamage(9); 
    e.beRepaired(5); 
    for (int i = 0; i < 10; i++) {
        e.beRepaired(1); 
    }
    e.beRepaired(3); 
    return 0;
}
