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

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		validateGrade(gradeToSign);
		validateGrade(gradeToExecute);
	}
Form::Form(const Form &copy) : _name(copy._name),
	_isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign),
	_gradeToExecute(copy._gradeToExecute) {
}

/*
** On ne peut pas assigner les variables en const et on ne copie
** que l'etat modifiable (isSigned, dans notre cas).
*/
Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
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
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

/*	Getters	*/
const std::string &Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int	Form::getGradeToSign() const {
	return _gradeToSign;
}

int	Form::getGradeToExecute() const {
	return _gradeToExecute;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
	os << "Form \"" << f.getName() << "\", signed: ";
	if (f.isSigned()) {
		os << "yes";
	} else {
		os << "no";
	}
	os << ", grade required to sign: " << f.getGradeToSign()
	   << ", grade required to execute: " << f.getGradeToExecute();
	return os;
}