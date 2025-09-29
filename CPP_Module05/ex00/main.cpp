/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:51:37 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/25 00:53:13 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat timmy("Timmy", 42);
	Bureaucrat angel("angel", 150);
	Bureaucrat error2("Error2", 1);
	
	std::cout << timmy << std::endl;
	std::cout << angel << std::endl;
	std::cout << error2 << std::endl;

	try {
		timmy.incrGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught : "  << e.what() << std::endl;
	}
	try {
		angel.decrGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	try {
		error2.incrGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "After the changement of grades" << std::endl;
	std::cout << timmy << std::endl;
	std::cout << angel << std::endl;
	std::cout << error2 << std::endl;
	
	return 0;
}