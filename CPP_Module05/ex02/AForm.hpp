/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:56:35 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/26 01:52:06 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private: //private because it's asked in the subject
		const		std::string _name;
		bool		_signed; //not signed in construction
		const int	_grToSign; // minimum grade to sign the form
		const int	_grToExecute; // same but for the execution
	
	public:
		AForm();
		AForm(const std::string &name, int grToSign, int grToExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		
		class GradeTooHighException : public std::exception {
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};

		const	std::string &getName() const;
		bool	checkSigned() const;
		int		getterGradeToSign() const;
		int		getterGradeToExecute() const;

		void	beSigned(const Bureaucrat &b); /*_isSigned will be updated if it's possible 
									if it's not it will throw GradeTooLow/highException/ */
		void	execute(Bureaucrat const &exec) const;
		protected :
		virtual void	actExecute(Bureaucrat const &executor) const = 0;
        //execute form ?
};

std::ostream &operator<<(std::ostream &os, const AForm &f);


#endif