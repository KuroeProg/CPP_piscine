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
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm* (Intern::*FormCreator)(const std::string &target) const;

    FormCreator creators[3] = {
        &Intern::addShrubbery,
        &Intern::addRobotomy,
        &Intern::addPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (nameForm == formNames[i]) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return (this->*creators[i])(target);
        }
    }

    std::cout << "Error: Intern cannot create " << nameForm
              << " because it doesn't exist !" << std::endl;
    return NULL;
}

