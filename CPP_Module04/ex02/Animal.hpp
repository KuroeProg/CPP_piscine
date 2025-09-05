/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:38:30 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/02 18:38:30 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal {
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &copie);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif