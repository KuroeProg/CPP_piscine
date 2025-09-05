/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:43:22 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/05 21:43:22 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &copie);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();

	void makeSound() const;
};

#endif