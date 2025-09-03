/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:49:13 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/03 15:49:13 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
        ideas[i] = "";
	std::cout << "Constructor for Brain called !" << std::endl;
}

Brain::Brain(const Brain &copie) {
	std::cout << "Copy constructor for Brain called !" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copie.ideas[i]; // Copying the ideas index by index
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Operator for Brain called !" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

void	Brain::setIdea(int index, const std::string &newIdea) {
	if (index >= 0 && index < 100) {
		ideas[index] = newIdea;
	}
}

std::string	Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}