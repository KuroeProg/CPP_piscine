/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:34:52 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/02 18:34:52 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	Dog a;
	Dog b(a);
	Dog c;
	c = b;

	Cat d;
	Cat e(d);
	Cat f;
	f = e;
	{
		Dog x;
		Dog z;
	}
	const int size = 4;
	Animal* animals[size];
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();
	for (int i = 0; i < size; i++)
		delete animals[i];

	Dog basic;
	basic.setIdea(0, "Chase the LetterMan");
	Dog copy = basic; 
	basic.setIdea(0, "Sleeping all day long");
	std::cout << "basic[0]: " << basic.getIdea(0) << "\n";
	std::cout << "copy[0]: " << copy.getIdea(0) << "\n";

	return 0;

}