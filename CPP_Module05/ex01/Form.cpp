/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:57:00 by cfiachet          #+#    #+#             */
/*   Updated: 2025/09/26 01:51:32 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


static void	validateGrade(int grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form()
    : _name("default"),
      _signed(false),
      _grToSign(150),
      _grToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _grToSign(gradeToSign), _grToExecute(gradeToExecute) {
		validateGrade(gradeToSign);
		validateGrade(gradeToExecute);
	}
Form::Form(const Form &copy) : _name(copy._name),
	_signed(copy._signed),
	_grToSign(copy._grToSign),
	_grToExecute(copy._grToExecute) {
}

/*
** On ne peut pas assigner les variables en const et on ne copie
** que l'etat modifiable (isSigned, dans notre cas).
*/
Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form() {
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low";
}

void	Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _grToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

/*	Getters	*/
const std::string &Form::getName() const {
	return _name;
}

bool Form::checkSigned() const {
	return _signed;
}

int	Form::getterGradeToSign() const {
	return _grToSign;
}

int	Form::getterGradeToExecute() const {
	return _grToExecute;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
	os << "Form \"" << f.getName() << "\", signed: ";
	if (f.checkSigned()) {
		os << "yes";
	} else {
		os << "no";
	}
	os << ", grade required to sign: " << f.getterGradeToSign()
	   << ", grade required to execute: " << f.getterGradeToExecute();
	return os;
}