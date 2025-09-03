/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:38:35 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/02 18:38:35 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &copie);
        Dog &operator=(const Dog &other);
        ~Dog();
        void setIdea(int idx, const std::string& idea) { brain->setIdea(idx, idea); }
        std::string getIdea(int idx) const { return brain->getIdea(idx); }

        void makeSound() const;
};

#endif