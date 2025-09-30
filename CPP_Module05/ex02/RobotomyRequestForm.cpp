#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy_Request_Form", 72, 45), _targ("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &targ) 
    : AForm("Robotomy_Request_Form", 72, 45), _targ(targ) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), _targ(copy._targ) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _targ = other._targ;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::actExecute(Bureaucrat const &executor) const {
    (void)executor;
    std::cout << "Some actual drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << _targ << " has been robotomized, uhuh~." << std::endl;
    else
        std::cout << "Error : The robotomy for " << _targ << " failed." << std::endl;
}
