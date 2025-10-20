# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery_Creation_Form", 145, 137), _targ("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targ) 
    : AForm("Shrubbery_Creation_Form", 145, 137), _targ(targ) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _targ(copy._targ) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _targ = other._targ;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::actExecute(Bureaucrat const &executor) const {
    (void)executor;
    std::ofstream fd((_targ + "_shrubbery").c_str());
    if (!fd) {
        std::cerr << "Error : Cannot open " << _targ << "_shrubbery" << std::endl;
        return ;
    }
    fd << "        __ _.--..--._ _" << std::endl;
    fd << "     .-' _/   _/\\_   \\_'-." << std::endl;
    fd << "    |__ /   _/\\__/\\_   \\__|" << std::endl;
    fd << "       |___/\\_\\__/  \\___|" << std::endl;
    fd << "              \\__/" << std::endl;
    fd << "              \\__/" << std::endl;
    fd << "               \\__/" << std::endl;
    fd << "                \\__/" << std::endl;
    fd << "             ____\\__/___" << std::endl;
    fd << "       . - '             ' -." << std::endl;
    fd << "      /                      \\" << std::endl;
    fd << "~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~  ~~~~~" << std::endl;
    fd << "  ~~~   ~~~~~   ~!~~   ~~ ~  ~ ~ ~~~~" << std::endl;

    fd.close();
}

