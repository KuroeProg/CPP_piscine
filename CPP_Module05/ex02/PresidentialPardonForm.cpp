#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential_Pardon_Form", 25, 5), _targ("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &targ) 
    : AForm("Presidential_Pardon_Form", 25, 5), _targ(targ) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm(copy), _targ(copy._targ) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _targ = other._targ;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::actExecute(Bureaucrat const &executor) const {
    (void)executor;
    std::cout << _targ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}