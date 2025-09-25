/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:51:37 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/26 01:51:10 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat timmy("Timmy", 42);
	Bureaucrat angel("angel", 150);
	Bureaucrat error2("Error2", 1);
	
	std::cout << timmy << std::endl;
	std::cout << angel << std::endl;
	std::cout << error2 << std::endl;
	try {
		timmy.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught : "  << e.what() << std::endl;
	}
	try {
		angel.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	try {
		error2.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	std::cout << "After the changement of grades" << std::endl;
	std::cout << timmy << std::endl;
	std::cout << angel << std::endl;
	std::cout << error2 << std::endl;

	/* added after, Form tests */
	Form tax("Tax Form", 50, 25);
	Form contrat("contrat Form", 10, 5);
	std::cout << tax << std::endl;
	std::cout << contrat << std::endl;
	/* Succes (timmy) and Error(angel)*/
	timmy.signForm(tax);
	angel.signForm(contrat);

	std::cout << tax << std::endl;
	std::cout << contrat << std::endl;
	
	return 0;
}