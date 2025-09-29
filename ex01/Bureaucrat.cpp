#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default"), _grade(grade)
{
	std::cout << "Bureaucrat Int constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat String constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat String and Int constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		this->_grade = grade;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

const std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::ostream & operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << "." << std::endl;
	return o;
}

void Bureaucrat::incrementGrade(void)
{
		setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
		setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}