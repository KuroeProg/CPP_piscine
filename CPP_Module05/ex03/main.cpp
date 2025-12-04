#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat Prom("Prom", 140);
        Bureaucrat Chiara("Chiara", 40);
        Bureaucrat Olivi3r("Olivi3r", 1);
        ShrubberyCreationForm tree("tree");
        RobotomyRequestForm bot("r2d2");
        PresidentialPardonForm mercy("Fry");
        std::cout << std::endl;

        Prom.signForm(tree);
        Prom.executeForm(tree);
        Chiara.signForm(tree);
        Chiara.executeForm(tree);
        std::cout << std::endl;

        Chiara.signForm(bot);
        Chiara.executeForm(bot);
        std::cout << std::endl;

        Chiara.signForm(mercy);
        Olivi3r.signForm(mercy);
        Olivi3r.executeForm(mercy);

        Intern intern;
        AForm *form = NULL;
        form = intern.makeForm("robotomy request", "Bender");
        if (form) {
            Olivi3r.signForm(*form);
            Olivi3r.executeForm(*form);
            delete form;
        }

        form = intern.makeForm("shrubbery creation", "garden");
        if (form) {
            Chiara.signForm(*form);
            Chiara.executeForm(*form);
            delete form;
        }

        form = intern.makeForm("coffee break", "42Perpi");
        if (form)
            delete form;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    

    return 0;
}
