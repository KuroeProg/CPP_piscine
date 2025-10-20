#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"


class Intern {
    private:
    AForm *addShrubbery(const std::string &target) const;
    AForm *addPresidential(const std::string &target) const;
    AForm *addRobotomy(const std::string &target) const;
    
    public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &other);
    ~Intern();
    
    AForm *makeForm(const std::string &nameForm, const std::string &target);
    
};

#endif