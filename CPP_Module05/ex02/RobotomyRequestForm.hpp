#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _targ;
	public:
        RobotomyRequestForm();
		RobotomyRequestForm(const std::string &targ);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
	protected:
		void	actExecute(Bureaucrat const &executor) const;
};


#endif