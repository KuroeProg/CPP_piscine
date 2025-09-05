/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:22:28 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/05 21:22:28 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copie);
        WrongAnimal &operator=(const WrongAnimal &other);
        virtual ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};

#endif