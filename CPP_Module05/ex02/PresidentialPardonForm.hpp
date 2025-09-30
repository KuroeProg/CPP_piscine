#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _targ;
	public:
        PresidentialPardonForm();
		PresidentialPardonForm(const std::string &targ);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
	protected:
		void	actExecute(Bureaucrat const &executor) const;
};




#endif