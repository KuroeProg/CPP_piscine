#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &copy) {
    (void)copy;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}



AForm *Intern::addShrubbery(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::addPresidential(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

AForm *Intern::addRobotomy(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(const std::string &nameForm, const std::string &target) {

    AForm *forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    const std::string strings[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; ++i) {
        if (nameForm == strings[i]) {
            std::cout << "Success: Intern creates " << nameForm << std::endl;
            for (int j = 0; j < 3; ++j)
                if (j != i) delete forms[j];
            return forms[i];
        }
    }
    std::cout << "Error: Intern wasn't enable to create " << nameForm
        << " because it doesn't exist !" << std::endl;
    for (int i = 0; i < 3; ++i)
        delete forms[i];
    return NULL;
}