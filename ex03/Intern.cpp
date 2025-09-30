#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
	}
	return *this;
}

static AForm* createShrubbery(const std::string & target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string & target) { return new RobotomyRequestForm(target); }
static AForm* createPresidential(const std::string & target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
    std::string formNames[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm* (*formCreators[3])(const std::string &) = { createShrubbery, createRobotomy, createPresidential };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Error: Form not found";
}