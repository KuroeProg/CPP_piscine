# include "AForm.hpp"

AForm::AForm(const std::string &name, int grToSign, int grToExecute) 
: _name(name), _signed(false), _grToSign(grToSign), _grToExecute(grToExecute) {
    if (grToSign < 1 || grToExecute < 1)
        throw GradeTooHighException();
    if (grToExecute > 150 || grToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
:   _name(copy._name), _signed(copy._signed),
   _grToSign(copy._grToSign), _grToExecute(copy._grToExecute) {
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm() {
}

const char  *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high !";
}

const char  *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low !";
}

const char  *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed !";
}

const	std::string &AForm::getName() const {
    return _name;
}

bool AForm::checkSigned() const {
    return _signed;
}

int AForm::getterGradeToSign() const {
    return _grToSign;
}

int AForm::getterGradeToExecute() const {
    return _grToExecute;
}

void    AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _grToSign)
        throw GradeTooLowException();
    _signed = true;
}

void    AForm::execute(Bureaucrat const &executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _grToExecute)
        throw GradeTooLowException();
    actExecute(executor);
}
