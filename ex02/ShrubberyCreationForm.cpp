#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream ofs((this->_target + "_shrubbery").c_str());
	if (ofs.fail())
		throw FileErrorException();
	ofs <<"     ###"
"      #o###"
"    #####o###"
"   #o#|#|#/###"
"    ####|/#o#"
"     # }|{  #"
"       }|{" << std::endl;
	ofs.close();
}

const char *ShrubberyCreationForm::FileErrorException::what() const throw()
{
	return "Error: could not open file";
}

