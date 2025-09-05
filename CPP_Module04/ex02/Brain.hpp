/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:41:21 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/03 15:41:21 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain &copie);
		Brain &operator=(const Brain &other);
		~Brain();

		void setIdea(int index, const std::string &newIdea); //set dogs and cats to idea
		std::string getIdea(int index) const; //get an index of the array of ideas
};

#endif