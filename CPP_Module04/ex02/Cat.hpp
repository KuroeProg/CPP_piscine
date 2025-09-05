/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:38:33 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/02 18:38:33 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &copie);
		Cat &operator=(const Cat &other);
		~Cat();
		void setIdea(int idx, const std::string& idea) { brain->setIdea(idx, idea); }
    	std::string getIdea(int idx) const { return brain->getIdea(idx); }

	void makeSound() const;
};

#endif