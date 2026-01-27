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

void ShrubberyCreationForm::executeAction() const 
{
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        throw FileErrorException();

    ofs <<
"       ###\n"
"      #o###\n"
"    #####o###\n"
"   #o#|#|#/###\n"
"    ####|/#o#\n"
"     # }|{  #\n"
"       }|{\n\n\n" 
"       *\n"
"      ***\n"
"     *****\n"
"    *******\n"
"   *********\n"
"      |||\n";
}


const char *ShrubberyCreationForm::FileErrorException::what() const throw()
{
	return "Error: could not open file";
}

