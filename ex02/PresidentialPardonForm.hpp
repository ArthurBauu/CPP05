#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string const	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm(const std::string target);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

		void executeAction() const;

};

#endif